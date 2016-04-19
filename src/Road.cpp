#include "Road.h"

Road:: Road(int road_id, string road_name, bool is_two_way) : road_id(road_id),
road_name(road_name), is_two_way(is_two_way){};

bool Road:: isIsTwoWay() const {
	return is_two_way;
}

void Road:: setIsTwoWay(bool isTwoWay) {
	is_two_way = isTwoWay;
}

int Road:: getRoadId() const {
	return road_id;
}

void Road:: setRoadId(int roadId) {
	road_id = roadId;
}

const string& Road:: getRoadName() const {
	return road_name;
}

void Road:: setRoadName(const string& roadName) {
	road_name = roadName;
}
