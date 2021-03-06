#ifndef MODELSLISTWIDGET_H
#define MODELSLISTWIDGET_H

#include <GL/glu.h>
#include <QAction>
#include <QColorDialog>
#include <QListWidget>
#include <QMouseEvent>


class ModelsListWidget : public QListWidget
{
    Q_OBJECT

private:
    QVector<GLuint> checked;    // List of checked items number
    QString selectedItem, referenceModel;   // Name of the selected model and the reference model
    QStringList pathsList;  // List of the models name

    QAction* referenceModelButton;

    void mousePressEvent(QMouseEvent *event);
    void changeItemsFont();


public:
    ModelsListWidget(QWidget *parent = 0);


signals:
    void addModel();
    void saveModels();
    void removeModels();
    void modelColor(QColor newColor);
    void addTexture();

    void selectedModelChanged(QString selectedItem);
    void referenceModelChanged(QString referenceModel);

    void updateList();
    QVector<GLuint> updateCheckedModels(QVector<GLuint> checked);


public slots:
    void emitAddModel();
    void emitSaveModels();
    void emitRemoveModels();
    void emitChangeColor();
    void changeColor(QColor newColor);
    void emitAddTexture();
    void emitReferenceModel();

    void updateModelsList(QStringList items);
    void updateCheckedModels();

    void setSelected(QListWidgetItem* item);
};

#endif // MODELSLISTWIDGET_H
