#include <QSettings>
#include "stereoplugin.h"
#include "settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);

    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
    m_level = settings.value("extra_stereo/intensity", 1.0).toDouble();
    m_ui.intensitySlider->setValue(m_level * 100 / 10.0);
}

SettingsDialog::~SettingsDialog()
{

}

void SettingsDialog::accept()
{
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
    settings.setValue("extra_stereo/intensity", m_ui.intensitySlider->value() * 10.0 / 100);
    QDialog::accept();
}

void SettingsDialog::SettingsDialog::reject()
{
    if(StereoPlugin::instance()) //restore settings
        StereoPlugin::instance()->setIntensity(m_level);
    QDialog::reject();
}

void SettingsDialog::on_intensitySlider_valueChanged(int value)
{
    double level = value * 10.0 / 100;
    m_ui.intensityLabel->setText(QString(tr("%1")).arg(level));
    if(StereoPlugin::instance())
        StereoPlugin::instance()->setIntensity(level);
}