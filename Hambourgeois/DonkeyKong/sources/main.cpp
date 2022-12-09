#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN

#include <windows.h>
#include <Engine.h>
#include <BaseScene.h>
#include <Animation.h>
#include <MarioController.h>
#include <PhysicsObject.h>
#include <Canvas.h>
#include <LineCollider.h>


class MainMenu : public hambourgeois::BaseScene {
public:
	virtual void Load();
	virtual void Update(float dt);
};

class Level1 : public hambourgeois::BaseScene {
public:
	virtual void Load();
	virtual void Update(float dt);

private:
	void ChangeBonusText(std::string canvasID, std::string textId);

	float timePassedInScene = 0.0f;
	float timeToChangeBonus = 2.0f;
	float nextTimeToChangeBonus = 2.0f;
	int currentBonus = 5000;
};


void InitGameplay(hambourgeois::Engine& engine)
{
	engine.World().Register("MainMenu", new MainMenu());
	engine.World().Register("Level1", new Level1());
	engine.World().Load("Level1");

	
	
	/*engine.World().Unload();
	engine.World().Load("Level1");*/
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR argv, _In_ INT argc)
{
	hambourgeois::Engine& engine = hambourgeois::Engine::Get();
	if (engine.Init("Donkey Kong", 224 * 3, 256 * 3))
	{
		InitGameplay(engine);
		engine.Start();
	}
	return 0;
}

void Level1::Load()
{
	hambourgeois::Engine& engine = hambourgeois::Engine::Get();
	int w, h;
	engine.Graphics().GetWindowSize(&w, &h);

	engine.Audio().PlayMusic(engine.Audio().LoadMusic("ressources/audio/loop.mp3"), -1);
	engine.Audio().SetVolume(75);

#pragma region Background
	hambourgeois::Entity* background;
	background = Instantiate("Background");
	hambourgeois::Sprite* bckSprite = background->AddComponent<hambourgeois::Sprite>();
	bckSprite->Load("ressources/images/25m.png");
	background->SetSize(224 * 3, 256 * 3);
#pragma endregion

#pragma region UI
	size_t font = engine.Graphics().LoadFont("ressources/fonts/dk.ttf", 20);
	hambourgeois::Entity* ui;
	ui = Instantiate("UI");
	hambourgeois::Canvas* canvas = ui->AddComponent<hambourgeois::Canvas>();
	canvas->AddText("1UP", "1UP", font, 55, 0, hambourgeois::Color::RED);
	canvas->AddText("Score", "000000", font, 10, 25, hambourgeois::Color::WHITE);
	canvas->AddText("HighScore", "000000", font, (w / 2) - 70.0f, 25, hambourgeois::Color::WHITE);
	canvas->AddText("Level", "01", font, 560.0f, 72.5f, hambourgeois::Color::BLUE);
	canvas->AddText("Bonus", "5000", font, 533.0f, 144.5f, hambourgeois::Color::AQUA);

#pragma endregion

#pragma region DK
	hambourgeois::Entity* dk;
	dk = Instantiate("Donkey Kong");
	dk->SetPosition(35, 156);
	dk->SetSize(44 * 3, 32 * 3);

	hambourgeois::Animation* anim = dk->AddComponent<hambourgeois::Animation>();
	anim->Load("ressources/images/dk.png");
	anim->Init(4, 44, 32);
	anim->AddClip("frame1", 0, 4, 1);
	anim->Play("frame1", true);
#pragma endregion

#pragma region Mario
	hambourgeois::Entity* mario;
	mario = Instantiate("Mario");
	mario->SetPosition(20.0f, 695.0f);
	mario->SetSize(16 * 3, 16 * 3);

	hambourgeois::Animation* marioAnim = mario->AddComponent<hambourgeois::Animation>();
	marioAnim->Load("ressources/images/mario_walk.png");
	marioAnim->Init(4, 16, 16);
	marioAnim->AddClip("walk", 0, 4, 0.1f);
	marioAnim->SetFlip(true, false);

	hambourgeois::PhysicsObject* marioPhysics = mario->AddComponent<hambourgeois::PhysicsObject>();
	marioPhysics->SetGravity(-9.8f);
	marioPhysics->SetTerminalVelocity(15.0f);

	hambourgeois::MarioController* controller = mario->AddComponent<hambourgeois::MarioController>();
	controller->SetMarioSpeed(75.0f);
	controller->SetJumpForce(225.0f);
	
	hambourgeois::Collider* collider = mario->AddComponent<hambourgeois::Collider>();
	collider->SetColor(hambourgeois::Color::RED);
	//collider->EnableDraw();

#pragma endregion

#pragma region Floor
	
	hambourgeois::Entity* f1;
	f1 = Instantiate("Floor1");
	f1->SetPosition(0, 744);
	f1->SetSize(335, 0);

	hambourgeois::LineCollider* f1collider = f1->AddComponent<hambourgeois::LineCollider>();
	f1collider->LineFromRect(true);
	f1collider->EnableDraw();

	hambourgeois::Entity* f2;
	f2 = Instantiate("Floor2");
	f2->SetPosition(335, 724);
	f2->SetSize(335, 20);

	hambourgeois::LineCollider* f2collider = f2->AddComponent<hambourgeois::LineCollider>();
	f2collider->LineFromRect(true);
	f2collider->EnableDraw();

	hambourgeois::Entity* f3;
	f3 = Instantiate("Floor3");
	f3->SetPosition(0, 622);
	f3->SetSize(620, 38);

	hambourgeois::LineCollider* f3collider = f3->AddComponent<hambourgeois::LineCollider>();
	f3collider->LineFromRect(false);
	f3collider->EnableDraw();

	hambourgeois::Entity* f4;
	f4 = Instantiate("Floor4");
	f4->SetPosition(50, 524);
	f4->SetSize(620, 38);

	hambourgeois::LineCollider* f4collider = f4->AddComponent<hambourgeois::LineCollider>();
	f4collider->LineFromRect(true);
	f4collider->EnableDraw();

	hambourgeois::Entity* f5;
	f5 = Instantiate("Floor5");
	f5->SetPosition(0, 426);
	f5->SetSize(620, 38);

	hambourgeois::LineCollider* f5collider = f5->AddComponent<hambourgeois::LineCollider>();
	f5collider->LineFromRect(false);
	f5collider->EnableDraw();

	hambourgeois::Entity* f6;
	f6 = Instantiate("Floor6");
	f6->SetPosition(50, 328);
	f6->SetSize(620, 38);

	hambourgeois::LineCollider* f6collider = f6->AddComponent<hambourgeois::LineCollider>();
	f6collider->LineFromRect(true);
	f6collider->EnableDraw();

	hambourgeois::Entity* f7;
	f7 = Instantiate("Floor7");
	f7->SetPosition(432, 254);
	f7->SetSize(189, 13);

	hambourgeois::LineCollider* f7collider = f7->AddComponent<hambourgeois::LineCollider>();
	f7collider->LineFromRect(false);
	f7collider->EnableDraw();

	hambourgeois::Entity* f8;
	f8 = Instantiate("Floor8");
	f8->SetPosition(0, 254);
	f8->SetSize(432, 0);

	hambourgeois::LineCollider* f8collider = f8->AddComponent<hambourgeois::LineCollider>();
	f8collider->LineFromRect(false);
	f8collider->EnableDraw();
	
#pragma endregion

#pragma region Ladder
	hambourgeois::Entity* l1;
	l1 = Instantiate("Ladder1");
	f1->SetPosition(240, 660);
	f1->SetSize(24, 84);

	hambourgeois::Collider* l1collider = f1->AddComponent<hambourgeois::Collider>();
	l1collider->SetLayer("Broken Ladder");
	l1collider->SetColor(hambourgeois::Color::BLUEVIOLET);
	l1collider->EnableDraw();

	hambourgeois::Entity* l2;
	l2 = Instantiate("Ladder2");
	l2->SetPosition(552, 678);
	l2->SetSize(24, 52);

	hambourgeois::Collider* l2collider = l2->AddComponent<hambourgeois::Collider>();
	l2collider->SetLayer("Ladder");
	l2collider->SetColor(hambourgeois::Color::VIOLET);
	l2collider->EnableDraw();
#pragma endregion


}

void Level1::Update(float dt)
{
	timePassedInScene += dt;
	ChangeBonusText("UI", "Bonus");
}

void Level1::ChangeBonusText(std::string canvasId, std::string textId)
{
	if (timePassedInScene >= nextTimeToChangeBonus)
	{
		currentBonus -= 100;
		nextTimeToChangeBonus += timeToChangeBonus;
		
		hambourgeois::Canvas* canvas = hambourgeois::Engine::Get().World().Find(canvasId)->GetComponent<hambourgeois::Canvas>();
		canvas->EditText(textId, std::to_string(currentBonus));
	}
}

void MainMenu::Load()
{
	
}

void MainMenu::Update(float dt)
{

}
