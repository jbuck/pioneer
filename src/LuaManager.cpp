#include "LuaManager.h"
#include "oolua/oolua.h"

std::auto_ptr<LuaManager> LuaManager::s_instance;

LuaManager::LuaManager() : m_lua(NULL) {
	m_lua = lua_open();

	luaL_openlibs(m_lua);

	lua_atpanic(m_lua, pi_lua_panic);

	// XXX remove once oolua is gone
	OOLUA::setup_user_lua_state(m_lua);
}

LuaManager::~LuaManager() {
	lua_close(m_lua);
}