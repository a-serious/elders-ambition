#include "eldersdestination.h"

EldersDestination::EldersDestination(int x, int y, int level, int from, EldersMap *parent)
    : EldersFloor(x, y, level, parent)
{
    this->from = from;
    appendClass("destination");
    switch (from)
    {
    case 1:
        property["label"] = "destination_down";
        break;
    case 0:
        property["label"] = "destination_up";
        break;
    }
}
