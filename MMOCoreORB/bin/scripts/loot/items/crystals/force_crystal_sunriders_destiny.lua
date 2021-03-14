force_crystal_sunriders_destiny = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "Sunrider's Destiny",
	directObjectTemplate = "object/tangible/component/weapon/lightsaber/lightsaber_module_force_crystal.iff",
	craftingValues = {
		{"mindamage",0,70,0},
		{"maxdamage",0,70,0},
		{"attackspeed",1,-1,5},
		{"woundchance",4,8,5},
		{"hitpoints",700,1000,0},
		{"attackhealthcost",9,0,0},
		{"attackactioncost",9,0,0},
		{"attackmindcost",9,0,0},
		{"forcecost",0,-1.0,5},
		{"color",29,29,0},
	},
	customizationStringNames = {},
	customizationValues = {}
}

addLootItemTemplate("force_crystal_sunriders_destiny", force_crystal_sunriders_destiny)