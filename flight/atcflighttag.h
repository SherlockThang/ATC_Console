#ifndef ATCFLIGHTTAG_H
#define ATCFLIGHTTAG_H

#include "atctagrect.h"
#include "atctagdiamond.h"
#include "atcflags.h"

#include <QGraphicsItem>

class ATCFlightTag
{
public:
    explicit ATCFlightTag();
    ~ATCFlightTag();

    ATC::TagType& getTagType();

    ATCTagDiamond* getDiamond();
    QPointF& getDiamondPosition();

    QGraphicsLineItem* getLeader();
    QPointF& getLeaderEndPosition();

    ATCTagRect* getTagBox();
    QGraphicsLineItem* getConnector();
    double getDX();
    double getDY();

    QGraphicsSimpleTextItem* getText();

    void setTagType(ATC::TagType t);

    void setDiamond(ATCTagDiamond *rect);
    void setDiamondPosition(QPointF &pos);

    void setLeader(QGraphicsLineItem *line);
    void setLeaderEndPosition(QPointF &pos);

    void setTagBox(ATCTagRect *rect);
    void setConnector(QGraphicsLineItem *line);
    void setDX(double deltaX);
    void setDY(double deltaY);

    void moveTo(QPointF &pos);

    void setText(QGraphicsSimpleTextItem *text);

    void hideTag();
    void showTag();

private:
    ATC::TagType type;

    ATCTagDiamond *diamond = nullptr;
    QPointF diamondPos;

    QGraphicsLineItem *leader = nullptr;
    QPointF leaderEnd;

    ATCTagRect *tagBox = nullptr;
    QGraphicsLineItem *connector = nullptr;

    QGraphicsSimpleTextItem *text = nullptr;

    double dx;
    double dy;
};

#endif // ATCFLIGHTTAG_H
