#ifndef MAINFORM_H
#define MAINFORM_H

#include <QtGui/QMainWindow>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qcommandlinkbutton.h>
#include <qdesktopwidget.h>
#include <qdatetime>
#include "ui_MainForm.h"
#include "AboutForm.h"
#include "../FATX/typedefs.h"
#include "../FATX/FATX/Helpers.h"
#include "../FATX/FATX/Drive.h"
#include "../FATX/IO/xDeviceFileStream.h"
#include "../FATX/FATX/StaticInformation.h"
#include "../FATX/FATX/stfspackage.h"
#include <map>
#include <QPainter>
#include "progressdialog.h"
#include <string>

#ifndef _WIN32
#include <sys/types.h>
#include <unistd.h>

#ifdef __APPLE__
#include <security/Authorization.h>
#include <security/AuthorizationTags.h>
#include <security/AuthorizationDB.h>
#endif
#endif

using namespace Streams;

class MainForm : public QMainWindow
{
        Q_OBJECT

public:
        MainForm(QWidget *parent = 0, Qt::WFlags flags = 0);
        ~MainForm();
public slots:
        void OnLoadDevicesClick( void );
        void ShowAbout( void );
        void OnTreeExpand(QTreeWidgetItem* Item);
        void OnCopyToLocalDiskClick( void );
private:
        QIcon iFolder;
        QIcon iDisk;
        QIcon iFile;
        QIcon iPartition;
        QIcon iUsb;        
        map<DWORD, QIcon*> Icons;

        Ui::MainFormClass ui;
        void                    Center          ( void );
        void                    DoEvents        ( void );
        std::string             GetItemPath     (QTreeWidgetItem* Item);
        vector<Drive*>           ActiveDrives;
        QTreeWidgetItem         *AddFolder      (QTreeWidgetItem *Item, Folder *f);
        QTreeWidgetItem         *AddFile        (QTreeWidgetItem *Item, File *f, Drive *device);
        void                    PopulateTreeItems(QTreeWidgetItem *Item, bool expand);
        Drive                   *GetCurrentItemDrive(QTreeWidgetItem* Item);
        void                    SetContextMenus ( void );
        std::string             GetCurrentItemPath( QTreeWidgetItem *Item );
};

#endif // MAINFORM_H
