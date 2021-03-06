#include "LuaStar.h"
#include "LuaUtils.h"

/*
 * Class: Star
 *
 * Class representing a star. Inherits from <Body>.
 */

template <> const char *LuaObject<Star>::s_type = "Star";

template <> void LuaObject<Star>::RegisterClass() {
	const char *l_parent = "Body";

	LuaObjectBase::CreateClass(s_type, l_parent, NULL, NULL, NULL);
	LuaObjectBase::RegisterPromotion(l_parent, s_type, LuaObject<Star>::DynamicCastPromotionTest);
}
