#pragma once
class BotContainer {
public:
	Bot easyEnemyTop;
	Bot easyEnemyBottom;
	Bot easyAlly;
	Base easyBlueBase;

	Bot middleEnemyTop;
	Bot middleEnemyBottom;
	Bot middleAlly;
	Base middleBlueBase;

	Bot hardEnemyTop;
	Bot hardEnemyBottom;
	Bot hardAlly;
	Base hardBlueBase;

	Bot killerEnemyTop;
	Bot killerEnemyBottom;
	Bot killerAlly;
	Base killerBlueBase;

	friend class Profile;
public:
	BotContainer(): 
		easyEnemyTop{Bot(rand() % 5 + 1, 40, 40, 10, 2, 200, 100)},
		easyEnemyBottom{ Bot(rand() % 5 + 1, 60, 40, 13, 1, 200, 100) },
		easyAlly{ Bot(rand() % 5 + 1, 40, 40, 13, 1, 200, 100) },
		easyBlueBase{ Base(1, 200, 0, 0, 1, 200, 100) },

		middleEnemyTop{ Bot(rand() % 5 + 1, 60, 80, 16, 2, 250, 80) },
		middleEnemyBottom{ Bot(rand() % 5 + 1, 80, 60, 13, 2, 250, 80) },
		middleAlly{ Bot(rand() % 5 + 1, 60, 60, 16, 2, 250, 80) },
		middleBlueBase{ Base(1, 300, 0, 0, 2, 200, 100) },

		hardEnemyTop{ Bot(rand() % 5 + 1, 80, 100, 16, 3, 300, 60) },
		hardEnemyBottom{ Bot(rand() % 5 + 1, 100, 80, 19, 4, 300, 60) },
		hardAlly{ Bot(rand() % 5 + 1, 80, 80, 19, 3, 300, 60) },
		hardBlueBase{ Base(1, 400, 0, 0, 3, 200, 100) },

		killerEnemyTop{ Bot(rand() % 5 + 1, 100, 100, 19, 4, 350, 40) },
		killerEnemyBottom{ Bot(rand() % 5 + 1, 100, 100, 16, 5, 350, 40) },
		killerAlly{ Bot(rand() % 5 + 1, 100, 100, 22, 4, 350, 40) },
		killerBlueBase{ Base(1, 500, 0, 0, 4, 200, 100) }
	{}
	
	~BotContainer() {}
};

