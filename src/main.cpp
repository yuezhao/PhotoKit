/******************************************************************************
	main.cpp: description
	Copyright (C) 2012 Wang Bin <wbsecg1@gmail.com>
	
	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
******************************************************************************/

#include <QtCore/QDir>
#include <QApplication>
#include "CmdParser.h"
#include "PhotoKitView.h"
#include "UiManager.h"
#include "Config.h"

using namespace PhotoKit;

int main(int argc, char *argv[])
{
    PhotoKit::CmdParser::parse(argc, argv);
    QApplication a(argc, argv);

	PhotoKit::PhotoKitView view;
	view.setFocus();
	PhotoKit::UiManager::instance()->init(&view);
    //view.showFullScreen();
    view.showMaximized();
    PhotoKit::UiManager::instance()->showImagesFromThumb(CmdParser::images);
    qDebug("PhotoKit thumbdir: %s", qPrintable(PhotoKit::Config::thumbDir));
	QDir().mkpath(PhotoKit::Config::thumbDir);
	return a.exec();
}
