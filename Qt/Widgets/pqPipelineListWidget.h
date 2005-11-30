
/// \file pqPipelineListWidget.h
/// \brief
///   The pqPipelineListWidget class is used to display the pipeline
///   in the form of a list.
///
/// \date 11/25/2005

#ifndef _pqPipelineListWidget_h
#define _pqPipelineListWidget_h

#include "QtWidgetsExport.h"
#include <QWidget>

class pqPipelineListModel;
class QModelIndex;
class QTreeView;
class QVTKWidget;
class vtkSMProxy;
class vtkSMSourceProxy;

class QTWIDGETS_EXPORT pqPipelineListWidget : public QWidget
{
  Q_OBJECT

public:
  pqPipelineListWidget(QWidget *parent=0);
  virtual ~pqPipelineListWidget();

  pqPipelineListModel *getListModel() const {return this->ListModel;}
  QTreeView *getTreeView() const {return this->TreeView;}

  vtkSMSourceProxy *getSelectedProxy() const;
  QVTKWidget *getCurrentWindow() const;

signals:
  void proxySelected(vtkSMSourceProxy *proxy);

public slots:
  void selectProxy(vtkSMProxy *proxy);
  void selectWindow(QVTKWidget *window);

private slots:
  void changeCurrent(const QModelIndex &current, const QModelIndex &previous);

private:
  pqPipelineListModel *ListModel;
  QTreeView *TreeView;
};

#endif
