/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#ifndef SFGE_COLLIDER_H
#define SFGE_COLLIDER_H

#include <engine/component.h>
#include <utility/json_utility.h>

#include <Box2D/Box2D.h>


namespace sfge
{

enum class ColliderType
{
	NONE,
	CIRCLE,
	RECTANGLE,
	LINE
};

class Collider : public Component
{
public:
	using Component::Component;
	void Init() override;
	void Update(float dt) override;
	void OnColliderEnter(Collider* collider);
	void OnColliderExit(Collider* collider);

	static Collider* LoadCollider(Engine& engine, GameObject* gameObject, json& componentJson);
protected:
	b2Fixture * m_Fixture = nullptr;
};
}

#endif