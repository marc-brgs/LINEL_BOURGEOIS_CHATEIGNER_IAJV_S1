#include "Effect.h"
#include <iostream>
void Effect::Execute(World& world) const {
	*world.GetResource(type) += offset;
}