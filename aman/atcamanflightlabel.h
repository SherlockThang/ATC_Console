#ifndef ATCAMANFLIGHTLABEL_H
#define ATCAMANFLIGHTLABEL_H

#include "atcflight.h"

#include <QPen>
#include <QTime>
#include <QPolygonF>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsScene>

class ATCAmanFlightLabel : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT

public:
    explicit ATCAmanFlightLabel(ATCFlight *flight, QTime *time);
    explicit ATCAmanFlightLabel(ATCFlight *flight, QTime *time, QPointF arrowPos);
    ~ATCAmanFlightLabel();

    void addToScene(QGraphicsScene *scene);
    void removeFromScene(QGraphicsScene *scene);
    void moveByInterval(double dx, double dy);

    void createLabelItems(QPointF arrowPos);

    void createTimeRangeBar(QGraphicsScene *scene, double topY, double height);
    void createSelector(QGraphicsScene *scene, double y);

    void select();
    void deselect();

    void showLabel();
    void hideLabel();

    bool isSelected();
    bool isHovered();
    bool isLabelVisible();
    bool isOnScene();

    bool isOnTime();
    bool isDeviated();
    bool isCompromised();

    void updateEtiquette();
    void updateRTA();
    void updateColor();

    void setPageNumber(int *number);

    QGraphicsLineItem* getTimeArrow();
    QGraphicsLineItem* getConnector();
    QGraphicsSimpleTextItem* getText();
    QGraphicsRectItem* getRangeBar();
    QGraphicsLineItem* getSelector();

    ATCFlight* getFlight();

signals:
    void signalFlightLabelSelected(ATCAmanFlightLabel *label);
    void signalLabelHovered(bool flag);

private:
    ATCFlight *flight;
    QTime *time;

    QGraphicsLineItem *timeArrow = nullptr;
    QGraphicsLineItem *connector = nullptr;
    QGraphicsSimpleTextItem *text = nullptr;

    QGraphicsRectItem *rangeBar = nullptr;
    QGraphicsLineItem *selector = nullptr;

    bool selected = false;
    bool hovered = false;
    bool labelVisible = true;
    bool onScene = false;

    int *pageNumber;

    void moveLine(QPointF newPos);

    void swapLine(QGraphicsLineItem *line);
    void swapPolygon(QGraphicsPolygonItem *polygon);
    void swapText(QGraphicsSimpleTextItem *text);
    void swapRect(QGraphicsRectItem *rect);
    void swapSide();

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // ATCAMANFLIGHTLABEL_H
