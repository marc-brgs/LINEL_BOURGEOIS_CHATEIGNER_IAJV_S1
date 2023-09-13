#include "Effect.h"
#include <iostream>
void Effect::Execute(World& world) const {
	//assert(world.GetResource(type) == nullptr);

	*world.GetResource(type) += offset;
}