#include "Collider.h"

Collider::Collider(RectangleShape& body) : _body(body)
{

}

bool Collider:: checkCollision(Collider& other, float push)
{
	//getting the position and half sizes of current entity and the other entity
	Vector2f otherPosition = other.getPosition();
	Vector2f otherHalfSize = other.getHalfSize();
	Vector2f thisPosition = getPosition();
	Vector2f thisHalfSize = getHalfSize();

	//finding change in x & y between entities
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	//finding intersect points between entities
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	//collision
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		//this clamps push to between 0 & 1
		push = std::min(std::max(push, 0.0f), 1.0f);

		//push in X
		if (intersectX > intersectY)
		{
			//Dx is positive
			if (deltaX > 0.0f)
			{
				Move(intersectX + (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			//Dx is negative
			else
			{
				Move(-intersectX + (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		//push in Y
		else
		{
			//Dy is positive
			if (deltaY > 0.0f)
			{
				Move(0.0, intersectY + (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			//Dy is negative
			else
			{
				Move(0.0f , -intersectY + (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}

		return true;
	}

	//no collision
	return false;
}