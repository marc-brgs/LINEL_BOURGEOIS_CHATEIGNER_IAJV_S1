#include "World.h"
#include <iostream>
#include <cassert>

bool World::operator>=(const World& other) const {
	return wood >= other.wood &&
		stone >= other.stone &&
		food >= other.food &&
		workers >= other.workers &&
		houses >= other.houses;
}

void World::Debug() const {
	std::cout << "Wood : " << this->wood << ", Stone : " << this->stone << ", Food : " << this->food << ", Workers : " << this->workers << ", Houses : " << this->houses << "\n";
}

int* World::GetResource(Resources type) {
	switch (type)
	{
	case Resources::Wood:
		return &wood;
	case Resources::Stone:
		return &stone;
	case Resources::Food:
		return &food;
	case Resources::Workers:
		return &workers;
	case Resources::Houses:
		return &houses;
	default:
		assert(false);
		return nullptr;
	}
}

void World::AddWood(int amount) {
	this->wood += amount;
}

int const World::GetWood() const {
	return this->wood;
}

void World::AddStone(int amount) {
	this->stone += amount;
}

int const World::GetStone() const {
	return this->stone;
}

void World::AddFood(int amount) {
	this->food += amount;
}

int const World::GetFood() const {
	return this->food;
}

void World::AddWorker(int amount) {
	this->workers += amount;
}

int const World::GetWorkers() const {
	return this->workers;
}

void World::AddHouse(int amount) {
	this->houses += amount;
}

int const World::GetHouses() const {
	return this->houses;
}