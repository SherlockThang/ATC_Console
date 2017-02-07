
#include "test_atcflight.h"

void Test_ATCFlight::test_constructObject()
{
    State state;
    state.x = 1;
    state.y = 2;
    state.h = 3;
    state.v = 4;
    state.hdg = 5;
    state.cm = BADA::Climb;
    state.fp = BADA::Approach;
    state.rpm = BADA::Off;
    state.shm = BADA::CAS;
    state.trm = BADA::High;
    state.am = BADA::Accelerate;

    QString sq = "1234";

    ATCPaths paths;
    ATCFlightPlanFactory factory(paths);
    ATCFlightPlan *fpl = factory.newFlightPlan(ATC::IFR, "EPWA", "EPKK", "F350", QTime(12, 30, 0, 0));

    ATCFlight foo(state, fpl, sq);

    QVERIFY(foo.getFlightPlan() == fpl);
    QVERIFY(foo.getFlightPlan()->getRoute().getDeparture() == "EPWA");
    QVERIFY(foo.getAssignedSquawk() == "1234");
    QVERIFY(foo.getState().x == 1);
    QVERIFY(foo.getState().y == 2);
    QVERIFY(foo.getState().h == 3);
    QVERIFY(foo.getState().v == 4);
    QVERIFY(foo.getState().hdg == 5);
    QVERIFY(foo.getState().cm == BADA::Climb);
    QVERIFY(foo.getState().fp == BADA::Approach);
    QVERIFY(foo.getState().rpm == BADA::Off);
    QVERIFY(foo.getState().shm == BADA::CAS);
    QVERIFY(foo.getState().trm == BADA::High);
    QVERIFY(foo.getState().am == BADA::Accelerate);
}

void Test_ATCFlight::test_setFlightPlan()
{
    State state;
    state.x = 1;
    state.y = 2;
    state.h = 3;
    state.v = 4;
    state.hdg = 5;
    state.cm = BADA::Climb;
    state.fp = BADA::Approach;
    state.rpm = BADA::Off;
    state.shm = BADA::CAS;
    state.trm = BADA::High;
    state.am = BADA::Accelerate;

    QString sq = "1234";

    ATCPaths paths;
    ATCFlightPlanFactory factory(paths);
    ATCFlightPlan *fpl = factory.newFlightPlan(ATC::IFR, "EPWA", "EPKK", "F350", QTime(12, 30, 0, 0));

    ATCFlight foo(state, fpl, sq);

    QVERIFY(foo.getFlightPlan() == fpl);
    QVERIFY(foo.getFlightPlan()->getRoute().getDeparture() == "EPWA");
    QVERIFY(foo.getAssignedSquawk() == "1234");
    QVERIFY(foo.getState().x == 1);
    QVERIFY(foo.getState().y == 2);
    QVERIFY(foo.getState().h == 3);
    QVERIFY(foo.getState().v == 4);
    QVERIFY(foo.getState().hdg == 5);
    QVERIFY(foo.getState().cm == BADA::Climb);
    QVERIFY(foo.getState().fp == BADA::Approach);
    QVERIFY(foo.getState().rpm == BADA::Off);
    QVERIFY(foo.getState().shm == BADA::CAS);
    QVERIFY(foo.getState().trm == BADA::High);
    QVERIFY(foo.getState().am == BADA::Accelerate);

    ATCFlightPlan *newFpl = factory.newFlightPlan(ATC::IFR, "EPWA", "EPPO", "F350", QTime(12, 0, 0, 0));
    foo.setFlightPlan(newFpl);
    QVERIFY(foo.getFlightPlan() == newFpl);
}

void Test_ATCFlight::test_setSquawk()
{
    State state;
    state.x = 1;
    state.y = 2;
    state.h = 3;
    state.v = 4;
    state.hdg = 5;
    state.cm = BADA::Climb;
    state.fp = BADA::Approach;
    state.rpm = BADA::Off;
    state.shm = BADA::CAS;
    state.trm = BADA::High;
    state.am = BADA::Accelerate;

    QString sq = "1234";

    ATCPaths paths;
    ATCFlightPlanFactory factory(paths);
    ATCFlightPlan *fpl = factory.newFlightPlan(ATC::IFR, "EPWA", "EPKK", "F350", QTime(12, 30, 0, 0));

    ATCFlight foo(state, fpl, sq);

    QVERIFY(foo.getFlightPlan() == fpl);
    QVERIFY(foo.getFlightPlan()->getRoute().getDeparture() == "EPWA");
    QVERIFY(foo.getAssignedSquawk() == "1234");
    QVERIFY(foo.getState().x == 1);
    QVERIFY(foo.getState().y == 2);
    QVERIFY(foo.getState().h == 3);
    QVERIFY(foo.getState().v == 4);
    QVERIFY(foo.getState().hdg == 5);
    QVERIFY(foo.getState().cm == BADA::Climb);
    QVERIFY(foo.getState().fp == BADA::Approach);
    QVERIFY(foo.getState().rpm == BADA::Off);
    QVERIFY(foo.getState().shm == BADA::CAS);
    QVERIFY(foo.getState().trm == BADA::High);
    QVERIFY(foo.getState().am == BADA::Accelerate);

    QString newSq = "3456";
    foo.setSquawk(newSq);
    QVERIFY(foo.getSquawk() == newSq);
}

void Test_ATCFlight::test_setAssignedSquawk()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    foo.setAssignedSquawk("1234");
    QVERIFY(foo.getAssignedSquawk() == "1234");
}

void Test_ATCFlight::test_setState()
{
    State state;
    state.x = 1;
    state.y = 2;
    state.h = 3;
    state.v = 4;
    state.hdg = 5;
    state.cm = BADA::Climb;
    state.fp = BADA::Approach;
    state.rpm = BADA::Off;
    state.shm = BADA::CAS;
    state.trm = BADA::High;
    state.am = BADA::Accelerate;

    QString sq = "1234";

    ATCPaths paths;
    ATCFlightPlanFactory factory(paths);
    ATCFlightPlan *fpl = factory.newFlightPlan(ATC::IFR, "EPWA", "EPKK", "F350", QTime(12, 30, 0, 0));

    ATCFlight foo(state, fpl, sq);

    QVERIFY(foo.getFlightPlan() == fpl);
    QVERIFY(foo.getFlightPlan()->getRoute().getDeparture() == "EPWA");
    QVERIFY(foo.getAssignedSquawk() == "1234");
    QVERIFY(foo.getState().x == 1);
    QVERIFY(foo.getState().y == 2);
    QVERIFY(foo.getState().h == 3);
    QVERIFY(foo.getState().v == 4);
    QVERIFY(foo.getState().hdg == 5);
    QVERIFY(foo.getState().cm == BADA::Climb);
    QVERIFY(foo.getState().fp == BADA::Approach);
    QVERIFY(foo.getState().rpm == BADA::Off);
    QVERIFY(foo.getState().shm == BADA::CAS);
    QVERIFY(foo.getState().trm == BADA::High);
    QVERIFY(foo.getState().am == BADA::Accelerate);

    State newState;
    newState.x = 10;
    newState.y = 20;
    newState.h = 30;
    newState.v = 40;
    newState.hdg = 50;
    newState.cm = BADA::Descend;
    newState.fp = BADA::Landing;
    newState.rpm = BADA::On;
    newState.shm = BADA::Mach;
    newState.trm = BADA::Low;
    newState.am = BADA::Constant;

    foo.setState(newState);
    QVERIFY(foo.getState().x == 10);
    QVERIFY(foo.getState().y == 20);
    QVERIFY(foo.getState().h == 30);
    QVERIFY(foo.getState().v == 40);
    QVERIFY(foo.getState().hdg == 50);
    QVERIFY(foo.getState().cm == BADA::Descend);
    QVERIFY(foo.getState().fp == BADA::Landing);
    QVERIFY(foo.getState().rpm == BADA::On);
    QVERIFY(foo.getState().shm == BADA::Mach);
    QVERIFY(foo.getState().trm == BADA::Low);
    QVERIFY(foo.getState().am == BADA::Constant);
}

void Test_ATCFlight::test_setTemp()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    Temp temp;
    temp.m = 100;
    temp.Cpowred = 0.5;
    temp.vStallAP = 1;
    temp.vStallCR = 2;
    temp.vStallIC = 3;
    temp.vStallLD = 4;
    temp.vStallTO = 5;
    temp.xoverAltClbM = 50;
    temp.xoverAltCrsM = 60;
    temp.xoverAltDesM = 70;
    temp.waypoints.append(QPair<double, double>(0.5, 0.8));
    temp.waypoints.append(QPair<double, double>(0.6, 0.9));

    foo.setTemp(temp);
    QVERIFY(foo.getTemp().m = 100);
    QVERIFY(foo.getTemp().Cpowred = 0.5);
    QVERIFY(foo.getTemp().vStallAP = 1);
    QVERIFY(foo.getTemp().vStallCR = 2);
    QVERIFY(foo.getTemp().vStallIC = 3);
    QVERIFY(foo.getTemp().vStallLD = 4);
    QVERIFY(foo.getTemp().vStallTO = 5);
    QVERIFY(foo.getTemp().xoverAltClbM = 50);
    QVERIFY(foo.getTemp().xoverAltCrsM = 60);
    QVERIFY(foo.getTemp().xoverAltDesM = 70);
    QVERIFY(foo.getTemp().waypoints.size() == 2);
    QVERIFY(foo.getTemp().waypoints.at(0).first == 0.5);
    QVERIFY(foo.getTemp().waypoints.at(0).second == 0.8);
    QVERIFY(foo.getTemp().waypoints.at(1).first == 0.6);
    QVERIFY(foo.getTemp().waypoints.at(1).second == 0.9);
}

void Test_ATCFlight::test_setNavMode()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    foo.setNavMode(ATC::Nav);
    QVERIFY(foo.getNavMode() == ATC::Nav);
}

void Test_ATCFlight::test_setTargetAltitude()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    foo.setTargetAltitude("F350");
    QVERIFY(foo.getTargetAltitude() == "F350");
}

void Test_ATCFlight::test_setTargetSpeed()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    foo.setTargetSpeed("447");
    QVERIFY(foo.getTargetSpeed() == "447");
}

void Test_ATCFlight::test_setHdgRestriction()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    foo.setHdgRestriction(182);
    QVERIFY(foo.getHdgRestriction() == 182);
}

void Test_ATCFlight::test_setNextFix()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    foo.setNextFix("EVINA");
    QVERIFY(foo.getNextFix() == "EVINA");
}

void Test_ATCFlight::test_setSimStartTime()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    foo.setSimStartTime(QTime(0, 1, 20, 0));
    QVERIFY(foo.getSimStartTime() == QTime(0, 1, 20, 0));
}

void Test_ATCFlight::test_setTag()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    ATCFlightTag *tag = new ATCFlightTag();

    QVERIFY(foo.getFlightTag() == nullptr);

    foo.setFlightTag(tag);
    QVERIFY(foo.getFlightTag() == tag);
}

void Test_ATCFlight::test_setFixList()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    QStringList list;
    list << "TEST1" << "TEST2";
    foo.setFixList(list);

    QVERIFY(foo.getFixList() == list);
}

void Test_ATCFlight::test_setMainFixList()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    QStringList list;
    list << "TEST1" << "TEST2";
    foo.setMainFixList(list);

    QVERIFY(foo.getMainFixList() == list);
}

void Test_ATCFlight::test_setRoutePrediction()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    ATCRoutePrediction *prediction1 = new ATCRoutePrediction();
    foo.setRoutePrediction(prediction1);
    QVERIFY(foo.getRoutePrediction() == prediction1);

    ATCRoutePrediction *prediction2 = new ATCRoutePrediction();
    foo.setRoutePrediction(prediction2);
    QVERIFY(foo.getRoutePrediction() == prediction2);
}

void Test_ATCFlight::test_setRunwayDeparture()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    QString rwy = "15";
    foo.setRunwayDeparture(rwy);
    QVERIFY(foo.getRunwayDeparture() == rwy);
}

void Test_ATCFlight::test_setRunwayDestination()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    QString rwy = "15";
    foo.setRunwayDestination(rwy);
    QVERIFY(foo.getRunwayDestination() == rwy);
}

void Test_ATCFlight::test_setSID()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    QString procedure = "OLILA5G";
    foo.setSID(procedure);
    QVERIFY(foo.getSID() == procedure);
}

void Test_ATCFlight::test_setSTAR()
{
    State state;
    state.x = 1;

    ATCFlight foo(state);

    QString procedure = "OLILA5G";
    foo.setSTAR(procedure);
    QVERIFY(foo.getSTAR() == procedure);
}

