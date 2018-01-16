#ifndef MUSICTOPLISTFOUNDWIDGET_H
#define MUSICTOPLISTFOUNDWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2018 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include "musicfoundabstractwidget.h"
#include "musiccategoryconfigmanager.h"

class MusicToplistFoundCategoryPopWidget;

/*! @brief The class of the toplist music found table widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicTopListFoundTableWidget : public MusicQueryFoundTableWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicTopListFoundTableWidget(QWidget *parent = 0);

    virtual ~MusicTopListFoundTableWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Set network query input.
     */
    virtual void setQueryInput(MusicDownLoadQueryThreadAbstract *query) override;

};


/*! @brief The class of toplist music found widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicTopListFoundWidget : public MusicFoundAbstractWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicTopListFoundWidget(QWidget *parent = 0);

    virtual ~MusicTopListFoundWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Set current name to search founds.
     */
    virtual void setSongName(const QString &name) override;
    /*!
     * Set current id to search founds.
     */
    virtual void setSongNameById(const QString &id) override;

    /*!
     * Resize window bound by widgte resize called.
     */
    virtual void resizeWindow() override;

public Q_SLOTS:
    /*!
     * Query all quality musics is finished.
     */
    void queryAllFinished();
    /*!
     * Create the current toplist info item.
     */
    void createToplistInfoItem(const MusicResultsItem &item);
    /*!
     * Current category changed.
     */
    void categoryChanged(const MusicPlaylistCategoryItem &category);

protected:
    /*!
     * Create init interface lables.
     */
    void createLabels();

    MusicToplistFoundCategoryPopWidget *m_categoryButton;

};

#endif // MUSICTOPLISTFOUNDWIDGET_H
