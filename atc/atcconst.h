#ifndef ATCCONST_H
#define ATCCONST_H

class ATCConst
{
public:
    ATCConst();

    static const double PI;

    static const double DEG_2_RAD;
    static const double RAD_2_DEG;

    static const double WGS84_RADIUS;
    static const double WGS84_FIRST_ECCENTRICITY;

    static const int DISPLAY_WIDTH = 1920;
    static const int DISPLAY_HEIGHT = 1020;

    static const int SCENE_FACTOR = 100;
    static const int SCENE_WIDTH = DISPLAY_WIDTH * SCENE_FACTOR;
    static const int SCENE_HEIGHT = DISPLAY_HEIGHT * SCENE_FACTOR;
    static const double SECTOR_SHRINK_FACTOR;

    static const double SECTORLINE_WIDTH;

    static const double FIX_LINE_WIDTH;
    static const double FIX_SIDE_LENGTH;
    static const double FIX_LABEL_HEIGHT;
    static const double FIX_LABEL_DX;
    static const double FIX_LABEL_DY;

};

#endif // ATCCONST_H