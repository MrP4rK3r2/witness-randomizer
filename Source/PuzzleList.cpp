// This is an open source non-commercial project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "PuzzleList.h"
#include "Watchdog.h"

void PuzzleList::GenerateAllN()
{
	generator->setLoadingData(336);
	CopyTargetsN();
	GenerateTutorialN();
	GenerateSymmetryN();
	GenerateQuarryN();
	GenerateBunkerN();
	GenerateSwampN();
	GenerateTreehouseN();
	GenerateTownN();
	GenerateVaultsN();
	GenerateTrianglePanelsN();
	GenerateOrchardN();
	GenerateDesertN();
	GenerateKeepN();
	GenerateJungleN();
	GenerateMountainN();
	GenerateCavesN();
	SetWindowText(_handle, L"Done!");
	(new ArrowWatchdog(0x0056E))->start(); //Easy way to close the randomizer when the game is done
	//GenerateShadowsN(); //Can't randomize
	//GenerateMonasteryN(); //Can't randomize
}

void PuzzleList::GenerateAllH()
{
	generator->setLoadingData(349);
	CopyTargetsH();
	GenerateTutorialH();
	GenerateSymmetryH();
	GenerateQuarryH();
	GenerateBunkerH();
	GenerateSwampH();
	GenerateTreehouseH();
	GenerateTownH();
	GenerateVaultsH();
	GenerateTrianglePanelsH();
	GenerateOrchardH();
	GenerateKeepH();
	GenerateMountainH();
	GenerateCavesH();
	GenerateDesertH();
	SetWindowText(_handle, L"Done!");
}

void PuzzleList::CopyTargetsN()
{
	/*
	* Target list for future
	* Optional Doors
	* Shadows Laser
	* Bunker Laser
	* Bunker Entry Door
	* Jungle Pop-up Wall
	* Monastary Laser
	* Monastary Laser Shortcut
	* Town Env Set
	* Town Star Door
	* Town Lattice Door Thing
	* UTM Elevator
	* 
	* Target pool for future
	* Tutorial Discard
	* Tutorial Vault
	* Sym Discard
	* Desert Discard
	* Desert Vault
	* Mill Control Room 2
	* Treehouse Purple Bridge 1 Last Panel
	* Treehouse Purple Bridge 2 Last Panel
	* Treehouse Green Bridge Last Panel
	* Treehouse Green Bridge Discard
	* Treehouse Laser Discard
	* Keep Purple Pressure Plates
	* Shipwreck Discard
	* Shipwreck Vault
	* Theater Discard
	* One Theater Exit
	* Town Orange Crate
	* Town Star Door
	* Town RGB
	* Town Rooftop Discard
	* Jungle Vault
	* Bunker Entry Door
	* Swamp Tutorial Set
	* Swamp Red Shortcut
	* Swamp Purple Shortcut
	* Swamp Final Shortcut
	* Mountainside Discard
	* Mountainside Vault
	* UTM Panels in General
	*/

	Special::copyTarget(0x033D4, 0x04CA4); // Tutorial Vault -> Tutorial Optional Door 2
	Special::copyTarget(0x17CFB, 0x0A171); // Tutorial Discard -> Tutorial Optinal Door 1
	Special::copyTarget(0x17D01, 0x19650); // Town Crate Discard -> Shadows Laser
	Special::copyTarget(0x00021, 0x28A0D); // Stones Tutorial -> Town Church Star Door
	Special::copyTarget(0x28A0D, 0x28A69); // Town Church Stars -> Town Lattice
	Special::copyTarget(0x17D27, 0x03713); // Keep Discard Panel -> Monastary Shortcut
	Special::copyTarget(0x17C71, 0x17CA4); // Town Rooftop Discard -> Monastary Laser
	Special::copyTarget(0x17F9B, 0x17CAB); // Jungle Discard -> Jungle Pop-up wall
	Special::copyTarget(0x00061, 0x17C2E); // Dots tutorial -> Bunker Entry Door
	Special::copyTarget(0x17C2E, 0x09DE0); // Bunker Entry Door -> Bunker Laser
 
	Special::setPower(0x28B39, true); // Town Red Hex Panel
	Special::setPower(0x3369D, true); // Lower Elevator Control
	Special::setPower(0x17CA4, true); // Monastary Laser
	Special::setPower(0x17CAB, true); // Jungle Pop-up Wall

	Special::clearTarget(0x28A69); // Town Lattice
	Special::clearTarget(0x0360E); // Keep Front Laser

	//To fix issues caused by previous versions of simga's. Don't know if it still applies now. Don't want to find out.
	Special::setPower(0x009AB, true); //Swamp underwater
	Special::setPower(0x28998, true); //Town Yellow Door
}

void PuzzleList::CopyTargetsH()
{
	Special::setPower(0x0005D, true);
	Special::setPower(0x0005E, true);
	Special::setPower(0x0005F, true);
	Special::setPower(0x00060, true);
	Special::setPower(0x00061, true);
	Special::copyTarget(0x0005D, 0x28B39);//Town Red Hexagonal Panel
	Special::copyTarget(0x0005E, 0x03616);//Jungle Laser
	Special::copyTarget(0x0005F, 0x19650);//Shadows Laser
	Special::copyTarget(0x00060, 0x17CA4);//Monastary Laser
	Special::copyTarget(0x00061, 0x03608);//Desert Laser
}

//Normal Mode

void PuzzleList::GenerateTutorialN()
{
	generator->setLoadingData(L"Tutorial", 23);
	generator->resetConfig();
	Special::drawSeedAndDifficulty(0x00064, seedIsRNG ? -1 : seed, false);
	Special::drawGoodLuckPanel(0x00182);
	//Mazes
	generator->setFlag(Generate::Config::FullGaps);
	generator->generateMaze(0x00293);
	generator->generateMaze(0x00295, 1, 1);
	generator->generateMaze(0x002C2);
	//2 starts maze
	generator->resetConfig();
	generator->generateMaze(0x0A3B2);
	//2 exits maze
	generator->generateMaze(0x0A3B5);
	//Secret back area
	generator->generate(0x0A171, Decoration::Dot_Intersection, 25, Decoration::Gap, 1);
	generator->generate(0x04CA4, Decoration::Dot_Intersection, 25, Decoration::Gap, 2);
	//Dots Tutorial
	generator->setFlag(Generate::Config::FullGaps);
	generator->generate(0x0005D, Decoration::Dot, 2);
	generator->generate(0x0005E, Decoration::Dot, 5, Decoration::Gap, 4);
	generator->generate(0x0005F, Decoration::Dot, 5, Decoration::Gap, 4);
	generator->generate(0x00060, Decoration::Start, 2, Decoration::Dot_Intersection, 6, Decoration::Gap, 4);
	generator->generate(0x00061, Decoration::Start, 3, Decoration::Dot_Intersection, 6, Decoration::Gap, 4);
	//Stones Tutorial
	generator->resetConfig();

	//These 4 don't work, so I changed how they work from the base game. Basically it is the same panel as stones 5 but with less stones. Stones 1 didn't work even after that change, so that's why starts and exits were needed.
	generator->setGridSize(3, 3);
	generator->generate(0x018AF, Decoration::Stone | Decoration::Color::Black, 2, Decoration::Stone | Decoration::Color::White, 2, Decoration::Start, 1, Decoration::Exit, 1);
	generator->generate(0x0001B, Decoration::Stone | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 2);
	generator->generate(0x012C9, Decoration::Stone | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 3);
	generator->generate(0x0001C, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 3);

	generator->resetConfig();
	generator->generate(0x0001D, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x0001E, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x0001F, Decoration::Stone | Decoration::Color::Black, 10, Decoration::Stone | Decoration::Color::White, 5);
	generator->generate(0x00020, Decoration::Stone | Decoration::Color::Black, 10, Decoration::Stone | Decoration::Color::White, 5);
	generator->generate(0x00021, Decoration::Stone | Decoration::Color::Black, 10, Decoration::Stone | Decoration::Color::White, 5);
}

void PuzzleList::GenerateSymmetryN()
{
	generator->setLoadingData(L"Symmetry", 30);
	generator->resetConfig();
	//Back Wall
	//generator->setFlag(Generate::Config::StartEdgeOnly);
	generator->setSymmetry(Panel::Symmetry::Vertical);
	generator->generate(0x00086, Decoration::Gap, 4);
	generator->generate(0x00087, Decoration::Gap, 4);
	generator->generate(0x00059, Decoration::Gap, 10);
	generator->generate(0x00062, Decoration::Gap, 15);
	generator->generate(0x0005C, Decoration::Gap, 45);

	//Kiln Rotational Set
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x0008D, Decoration::Gap, 4);
	generator->generate(0x00081, Decoration::Gap, 4);
	generator->generate(0x00083, Decoration::Gap, 7);

	//Melting Set
	//TODO: Make these 3 the same puzzle
	generator->generate(0x00084, Decoration::Gap, 15);
	generator->generate(0x00082, Decoration::Gap, 15);
	generator->generate(0x0343A, Decoration::Gap, 15);

	//Black Dots
	generator->setSymmetry(Panel::Symmetry::Horizontal);
	generator->generate(0x00022, Decoration::Dot, 6);
	generator->generate(0x00023, Decoration::Dot, 3);
	generator->generate(0x00024, Decoration::Dot, 7);
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x00025, Decoration::Dot, 7);
	generator->generate(0x00026, Decoration::Dot, 6);

	//Colored Dots
	generator->setSymmetry(Panel::Symmetry::Vertical);
	generator->generate(0x0007C, Decoration::Dot | Decoration::Color::Blue, 3, Decoration::Dot | Decoration::Color::Yellow, 3);
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x0007E, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1);
	generator->generate(0x00075, Decoration::Dot | Decoration::Color::Blue, 2, Decoration::Dot | Decoration::Color::Yellow, 2);

	//This one doesn't work.
	//generator->resetConfig();
	//generator->setSymmetry(Panel::Symmetry::Rotational);
	//generator->generate(0x00073, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1, Decoration::Dot, 1);

	generator->generate(0x00077, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1, Decoration::Dot, 1);
	generator->generate(0x00079, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 2, Decoration::Dot, 4);

	//Fading Lines
	generator->generate(0x00065, Decoration::Dot | Decoration::Color::Blue, 4, Decoration::Dot | Decoration::Color::Yellow, 2);
	generator->generate(0x0006D, Decoration::Dot | Decoration::Color::Blue, 2, Decoration::Dot | Decoration::Color::Yellow, 4);
	generator->generate(0x00072, Decoration::Dot | Decoration::Color::Blue, 3, Decoration::Dot | Decoration::Color::Yellow, 1);
	//generator->setSymmetry(Panel::Symmetry::Vertical);
	//generator->generate(0x0006F, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1);
	//generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x00070, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1);
	generator->generate(0x00071, Decoration::Dot | Decoration::Color::Blue, 2, Decoration::Dot | Decoration::Color::Yellow, 1);
	generator->generate(0x00076, Decoration::Dot | Decoration::Color::Yellow, 3);

	//Doors
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::FullGaps);
	generator->generate(0x000B0, Decoration::Gap, 1, Decoration::Dot, 4);
	generator->generate(0x1C349, Decoration::Dot, 2);

	//Laser Blue and Yellow
	//These puzzles are kind of weird in that looks like a fullGap/regular break hybrid, and so I decided to keep the structure.
	generator->resetConfig();
	generator->setFlag(Generate::Config::PreserveStructure);
	specialCase->generateReflectionDotPuzzle(generator, 0x00A52, 0x00A61, { {Decoration::Dot, 5 },
		  {Decoration::Gap, 4} }, Panel::Symmetry::Vertical, false);
	//specialCase->generateReflectionDotPuzzle(generator, 0x00A57, 0x00A64, { {Decoration::Dot, 6 },
		  //{Decoration::Gap, 1} }, Panel::Symmetry::Vertical, false);
	specialCase->generateReflectionDotPuzzle(generator, 0x00A5B, 0x00A68, { {Decoration::Dot, 8 },
		  }, Panel::Symmetry::Rotational, false);
}

void PuzzleList::GenerateQuarryN()
{
	generator->setLoadingData(L"Quarry", 39);
	generator->resetConfig();
	
}

void PuzzleList::GenerateBunkerN()
{
	generator->resetConfig();
	generator->generate(0x17C2E, Decoration::Stone | Decoration::Color::White, 2, Decoration::Stone | Decoration::Color::Black, 2);

	//TODO: Attempt to randomize the rest of bunker by changing the color of the alreadly-placed stones.
}

void PuzzleList::GenerateSwampN()
{
	generator->setLoadingData(L"Swamp", 49);
	generator->resetConfig();
	
}

void PuzzleList::GenerateTreehouseN()
{
	generator->setLoadingData(L"Treehouse", 57);
	generator->resetConfig();

}

void PuzzleList::GenerateTownN()
{
	generator->setLoadingData(L"Town", 20);
	generator->resetConfig();
}

void PuzzleList::GenerateVaultsN()
{
	generator->setLoadingData(L"Vaults", 5);
	generator->resetConfig();
	//Tutorial Vault
	generator->generate(0x033D4, Decoration::Start, 4, Decoration::Dot, 8, Decoration::Stone | Decoration::Color::Black, 7, Decoration::Stone | Decoration::Color::White, 7);
}

void PuzzleList::GenerateTrianglePanelsN()
{
	generator->setLoadingData(L"Triangles", 12);
	generator->resetConfig();
	//Tutorial Discard
	generator->generate(0x17CFB, Decoration::Triangle | Decoration::Color::Orange, 1, Decoration::Gap, 5);
	//Sym Discard
	generator->generate(0x3C12B, Decoration::Triangle | Decoration::Color::Orange, 1, Decoration::Gap, 4);
}

void PuzzleList::GenerateMountainN()
{
	std::wstring text = L"Mountain Perspective";
	SetWindowText(_handle, text.c_str());
	generator->setFlagOnce(Generate::SplitStones);


	generator->setLoadingData(L"Mountain", 39);
	generator->resetConfig();
	

}

void PuzzleList::GenerateCavesN()
{
	generator->setLoadingData(L"Caves", 51);
	generator->resetConfig();
	

}

void PuzzleList::GenerateOrchardN()
{
	generator->resetConfig();

}

void PuzzleList::GenerateDesertN()
{
	generator->resetConfig();

}

void PuzzleList::GenerateKeepN()
{
	generator->setLoadingData(L"Keep", 5);
	generator->resetConfig();

}

void PuzzleList::GenerateJungleN()
{
	generator->resetConfig();


}

//--------------------------HARD MODE-----------------------------

void PuzzleList::GenerateTutorialH()
{
	generator->setLoadingData(L"Tutorial", 21);
	generator->resetConfig();
	Special::drawSeedAndDifficulty(0x00064, seedIsRNG ? -1 : seed, true);
	Special::drawGoodLuckPanel(0x00182);
	//Mazes
	generator->generate(0x00293);
	generator->generate(0x00295);
	generator->generate(0x002C2);
	//2 starts maze
	generator->generate(0x0A3B2);
	//2 exits maze
	generator->generate(0x0A3B5);
	//Exit Gate
	//generator->generate(0x03629);
	//Pillar + Patio
	generator->generate(0x0C335);
	generator->generate(0x0C373);
	//Secret back area
	generator->generate(0x0A171);
	generator->generate(0x04CA4);
	//Dots Tutorial
	generator->generate(0x0005D);
	generator->generate(0x0005E);
	generator->generate(0x0005F);
	generator->generate(0x00060);
	generator->generate(0x00061);
	//Stones Tutorial
	generator->generate(0x018AF);
	generator->generate(0x0001B);
	generator->generate(0x012C9);
	generator->generate(0x0001C);
	generator->generate(0x0001D);
	generator->generate(0x0001E);
	generator->generate(0x0001F);
	generator->generate(0x00020);
	generator->generate(0x00021);
}

void PuzzleList::GenerateSymmetryH()
{
	generator->setLoadingData(L"Symmetry", 34);
	generator->resetConfig();
	//Back Wall
	generator->generate(0x00086);
	generator->generate(0x00087);
	generator->generate(0x00059);
	generator->generate(0x00062);
	generator->generate(0x0005C);
	//Kiln 1-3
	generator->generate(0x0008D);
	generator->generate(0x00081);
	generator->generate(0x00083);
	//Melting 1-3
	generator->generate(0x00084);
	generator->generate(0x00082);
	generator->generate(0x0343A);
	//Symmetry Island Door
	generator->generate(0x000B0);
	//Black Dots
	generator->generate(0x00022);
	generator->generate(0x00023);
	generator->generate(0x00024);
	generator->generate(0x00025);
	generator->generate(0x00026);
	//B/Y Dots
	generator->generate(0x0007C);
	generator->generate(0x0007E);
	generator->generate(0x00075);
	generator->generate(0x00073);
	generator->generate(0x00077);
	generator->generate(0x00079);
	//Fading Lines Set
	generator->generate(0x00065);
	generator->generate(0x0006D);
	generator->generate(0x00072);
	/*generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x0006F);*/
	generator->generate(0x00070);
	generator->generate(0x00071);
	generator->generate(0x00076);
	//Symmetry Island Door 2
	generator->generate(0x1C349);
	//Dot Reflection Dual Panels (before laser)
	//generator->setFlag(Generate::Config::PreserveStructure);
	generator->setFlag(Generate::Config::DecorationsOnly);
	generator->generate(0x00A61);
	generator->generate(0x00A64);
	generator->generate(0x00A68);
	generator->generate(0x00A52);
	generator->generate(0x00A57);
	generator->generate(0x00A5B);
}

void PuzzleList::GenerateQuarryH()
{
	generator->setLoadingData(L"Quarry", 40);
	generator->resetConfig();
	//Entry Gates
	generator->generate(0x09E57);
	generator->generate(0x17C09);
	//Mill Entry Door
	generator->generate(0x01E5A);
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	//generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x01E59);
	//Lower Row
	generator->generate(0x00E0C);
	generator->generate(0x01489);
	generator->generate(0x0148A);
	generator->generate(0x014D9);
	generator->generate(0x014E7);
	generator->generate(0x014E8);
	//Upper Row
	generator->generate(0x00557);
	generator->generate(0x005F1);
	generator->generate(0x00620);
	generator->generate(0x009F5);
	generator->generate(0x0146C);
	generator->generate(0x3C12D);
	generator->generate(0x03686);
	generator->generate(0x014E9);
	//Control Room
	generator->generate(0x0367C);
	generator->generate(0x3C125);
	//Stairs
	generator->generate(0x03677);
	//Boathouse Ramp Activation
	generator->generate(0x034D4);
	generator->generate(0x021D5);
	//Boathouse Ramp and Hook
	generator->generate(0x03852);
	generator->generate(0x03858);
	generator->generate(0x275FA);
	//Boathouse Right Side
	generator->generate(0x021B3);
	generator->generate(0x021B4);
	generator->generate(0x021B0);
	generator->generate(0x021AF);
	generator->generate(0x021AE);
	//Boathouse Left Side Towards Shadows
	generator->generate(0x021B5);
	generator->generate(0x021B6);
	generator->generate(0x021B7);
	generator->generate(0x021BB);
	generator->generate(0x09DB5);
	generator->generate(0x09DB1);
	generator->generate(0x3C124);
	generator->generate(0x09DB3);
	generator->generate(0x09DB4);
	//Boathouse Left Side Towards Desert
	generator->generate(0x0A3CB);
	generator->generate(0x0A3CC);
	generator->generate(0x0A3D0);
	//Laser Puzzle
	generator->generate(0x03612);
}

void PuzzleList::GenerateBunkerH()
{
	// I wonder how many people will try these normally lmao
	generator->generate(0x09D9F);
	generator->generate(0x09DA1);
	generator->generate(0x09DA2);
	generator->generate(0x09DAF);
	//generator->generate(0x0A079);
	generator->generate(0x17C2E);
	generator->generate(0x0A010);
	generator->generate(0x0A01B);
	generator->generate(0x0A01F);
	generator->generate(0x09F7D);
	generator->generate(0x09FDC);
	generator->generate(0x09FF7);
	generator->generate(0x09F82);
	generator->generate(0x09FF8);
	generator->generate(0x17E63);
	generator->generate(0x17E67);
}

void PuzzleList::GenerateSwampH()
{
	generator->setLoadingData(L"Swamp", 55);
	generator->resetConfig();
	generator->generate(0x0056E);
	//First row tutorial
	generator->generate(0x00469);
	generator->generate(0x00472);
	generator->generate(0x00262);
	generator->generate(0x00474);
	generator->generate(0x00553);
	generator->generate(0x0056F);
	//Second Row tutorial
	generator->generate(0x00390);
	generator->generate(0x010CA);
	generator->generate(0x00983);
	generator->generate(0x00984);
	generator->generate(0x00986);
	generator->generate(0x00985);
	generator->generate(0x00987);
	generator->generate(0x181A9);
	//Modify bridge
	generator->generate(0x00609);
	generator->generate(0x18488);
	//Red Panels
	generator->generate(0x00982);
	generator->generate(0x0097F);
	generator->generate(0x0098F);
	generator->generate(0x00990);
	//Red Shortcut
	generator->generate(0x17C0D);
	generator->generate(0x17C0E);
	//Disconnected Shapes
	generator->generate(0x00999);
	generator->generate(0x0099D);
	generator->generate(0x009A0);
	generator->generate(0x009A1);
	//Modify rotating bridge
	generator->generate(0x181F5);
	//Stuff After rotating bridge I guess?
	generator->generate(0x00007);
	generator->generate(0x00008);
	generator->generate(0x00009);
	generator->generate(0x0000A);
	generator->generate(0x003B2);
	generator->generate(0x00A1E);
	generator->generate(0x00C2E);
	generator->generate(0x00E3A);
	//Optional Tetris
	generator->generate(0x009A6);
	//Negative Shapes 1
	generator->generate(0x009AB);
	generator->generate(0x009AD);
	generator->generate(0x009AE);
	generator->generate(0x009AF);
	generator->generate(0x00006);
	//Negative Shapes 2
	generator->generate(0x00002);
	generator->generate(0x00004);
	generator->generate(0x00005);
	generator->generate(0x013E6);
	generator->generate(0x00596);
	//Negative Shapes 3
	generator->generate(0x00001);
	generator->generate(0x014D2);
	generator->generate(0x014D4);
	generator->generate(0x014D1);
	//Modify Swamp Island
	//generator->generate(0x17C0A);
	//generator->generate(0x17E07);
	//Exit Shortcut
	generator->generate(0x17C05);
	generator->generate(0x17C02);
	//Flood Gate
	generator->generate(0x17E2B);
}

void PuzzleList::GenerateTreehouseH()
{
	generator->setLoadingData(L"Treehouse", 58);
	generator->resetConfig();
	//Doors
	generator->generate(0x0288C);
	generator->generate(0x02886);
	generator->generate(0x0A182);
	//Yellow Bridge
	generator->setFlag(Generate::Config::TreehouseLayout);
	generator->generate(0x17D72);
	generator->generate(0x17D8F);
	generator->generate(0x17D74);
	generator->generate(0x17DAC);
	generator->generate(0x17D9E);
	generator->generate(0x17DB9);
	generator->generate(0x17D9C);
	generator->generate(0x17DC2);
	generator->generate(0x17DC4);
	//Pink Bridge 1
	generator->generate(0x17DC8);
	generator->generate(0x17DC7);
	generator->generate(0x17CE4);
	generator->generate(0x17D2D);
	generator->generate(0x17D6C);
	//Pink Bridge 2
	generator->generate(0x17D9B);
	generator->generate(0x17D99);
	generator->generate(0x17DAA);
	generator->generate(0x17D97);
	generator->generate(0x17BDF);
	generator->generate(0x17D91);
	generator->generate(0x17DC6);
	//Orange Bridge 1	
	generator->generate(0x17DB3);
	generator->generate(0x17DB5);
	generator->generate(0x17DB6);
	generator->generate(0x17DC0);
	generator->generate(0x17DD7);
	generator->generate(0x17DD9);
	generator->generate(0x17DB8);
	generator->generate(0x17DDC);
	generator->generate(0x17DD1);
	generator->generate(0x17DDE);
	generator->generate(0x17DE3);
	generator->generate(0x17DEC);
	generator->generate(0x17DAE);
	generator->generate(0x17DB0);
	generator->generate(0x17DDB);
	//Orange Bridge 2
	generator->generate(0x17D88);
	generator->generate(0x17DB4);
	generator->generate(0x17D8C);
	generator->generate(0x17CE3);
	generator->generate(0x17DCD);
	generator->generate(0x17DB2);
	generator->generate(0x17DCC);
	generator->generate(0x17DCA);
	generator->generate(0x17D8E);
	generator->generate(0x17DB7);
	generator->generate(0x17DB1);
	generator->generate(0x17DA2);
	//Green Bridge
	generator->generate(0x17E3C);
	generator->generate(0x17E4D);
	generator->generate(0x17E4F);
	generator->generate(0x17E52);
	generator->generate(0x17E5B);
	generator->generate(0x17E5F);
	generator->generate(0x17E61);
	//Drawbridge
	generator->generate(0x037FF);
}

void PuzzleList::GenerateTownH()
{
	generator->setLoadingData(L"Town", 21);
	generator->resetConfig();
	//Full Dots + Triangles
	generator->generate(0x2899C);
	generator->generate(0x28A33);
	generator->generate(0x28ABF);
	generator->generate(0x28AC0);
	generator->generate(0x28AC1);
	generator->generate(0x28AD9);

	//generator->generate(0x2896A);

	//Blue Symmetry
	generator->generate(0x28AC7);
	generator->generate(0x28AC8);
	generator->generate(0x28ACA);
	generator->generate(0x28ACB);
	generator->generate(0x28ACC);
	//Glass Door
	generator->generate(0x28998);
	//Church Star Door
	generator->generate(0x28A0D);	//3-color Room
	//Modify switch to remove green
	generator->generate(0x334D8);
	generator->generate(0x03C0C);
	generator->generate(0x03C08);
	//Orange Crate
	generator->generate(0x0A0C8);
	//Windmill Puzzles
	generator->generate(0x17D02);
	/*generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x17F5F);*/
	//Theater Puzzles
	generator->generate(0x17F89);
	generator->generate(0x0A168);
	generator->generate(0x33AB2);
}

void PuzzleList::GenerateVaultsH()
{
	generator->setLoadingData(L"Vaults", 5);
	generator->resetConfig();
	//Tutorial Vault
	generator->generate(0x033D4);
	//Desert Vault
	generator->generate(0x0CC7B);
	//Symmetry Vault
	generator->generate(0x002A6);
}

void PuzzleList::GenerateTrianglePanelsH()
{
	generator->setLoadingData(L"Arrows", 14);
	generator->resetConfig();
	generator->generate(0x17CFB);
	generator->generate(0x3C12B);
	generator->generate(0x17CE7);
	generator->generate(0x17CF0);
	generator->generate(0x17C71);
	generator->generate(0x17CF7);
	generator->generate(0x17D01);
	generator->generate(0x17F9B);
	generator->generate(0x17D27);
	generator->generate(0x17D28);
	generator->generate(0x17FA9);
	generator->generate(0x17FA0);
	generator->generate(0x17C42);
	generator->generate(0x17F93);
	generator->resetConfig();
}

void PuzzleList::GenerateMountainH()
{
	std::wstring text = L"Mountain Perspective";
	generator->resetConfig();
	specialCase->generateMountaintop(0x17C34, { { Decoration::Stone | Decoration::Color::Black, 1 } });
	generator->setLoadingData(L"Mountain", 39);
	//Purple Bridge
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x09E39);
	//Orange Row
	generator->generate(0x09E73);
	generator->generate(0x09E75);
	generator->generate(0x09E78);
	generator->generate(0x09E79);
	generator->generate(0x09E6C);
	generator->generate(0x09E6F);
	generator->generate(0x09E6B);
	//Green Row
	generator->generate(0x09E7A);
	generator->generate(0x09E71);
	generator->generate(0x09E72);
	generator->generate(0x09E69);
	generator->generate(0x09E7B);
	//Purple Panels
	generator->generate(0x09EAD);
	generator->generate(0x09EAF);
	//Blue Row
	generator->generate(0x33AF5);
	generator->generate(0x33AF7);
	generator->generate(0x09F6E);
	//Level 2 Bridges
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x09E86);
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x09ED8);
	//Rainbow Row
	generator->generate(0x09FD3);
	generator->generate(0x09FD4);
	generator->generate(0x09FD6);
	generator->generate(0x09FD7);
	generator->generate(0x09FD8);
	//Multipnael
	generator->generate(0x09FCC);
	generator->generate(0x09FCE);
	generator->generate(0x09FCF);
	generator->generate(0x09FD0);
	generator->generate(0x09FD1);
	generator->generate(0x09FD2);
	//Elevator
	/*generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x09EEB);*/
	//Pillar Puzzles
	generator->generate(0x0383D);
	generator->generate(0x0383A);
	generator->generate(0x0383F);
	generator->generate(0x09E56);
	generator->generate(0x03859);
	generator->generate(0x09E5A);
	//generator->generate(0x339BB);
	//generator->generate(0x33961);
}

void PuzzleList::GenerateCavesH()
{
	generator->setLoadingData(L"Caves", 51);
	generator->resetConfig();
	generator->generate(0x17FA2);
	//Arrow Puzzles
	generator->generate(0x00FF8);
	generator->generate(0x01A0D);
	generator->generate(0x018A0);
	generator->generate(0x009A4);
	generator->generate(0x00A72);
	generator->generate(0x00190);
	generator->generate(0x00558);
	generator->generate(0x00567);
	generator->generate(0x006FE);
	generator->generate(0x008B8);
	generator->generate(0x00973);
	generator->generate(0x0097B);
	generator->generate(0x0097D);
	generator->generate(0x0097E);
	generator->generate(0x00994);
	generator->generate(0x334D5);
	generator->generate(0x00995);
	generator->generate(0x00996);
	generator->generate(0x00998);
	//First alcove
	generator->generate(0x32962);
	generator->generate(0x32966);
	generator->generate(0x01A31);
	generator->generate(0x00B71);
	//Perspective
	generator->generate(0x288EA);
	generator->generate(0x288FC);
	generator->generate(0x289E7);
	generator->generate(0x288AA);
	//Full Dots + Arrows
	generator->generate(0x0A16B);
	generator->generate(0x0A2CE);
	generator->generate(0x0A2D7);
	generator->generate(0x0A2DD);
	generator->generate(0x0A2EA);
	generator->generate(0x17FB9);
	//Invisible Symbols
	generator->generate(0x0008F);
	generator->generate(0x0006B);
	generator->generate(0x0008B);
	generator->generate(0x0008C);
	generator->generate(0x0008A);
	generator->generate(0x00089);
	generator->generate(0x0006A);
	generator->generate(0x0006C);
	generator->generate(0x00027);
	generator->generate(0x00028);
	generator->generate(0x00029);
	//Arrows Exit
	generator->generate(0x17CF2);
	//Stars Exit
	generator->generate(0x021D7);
	//Elevators
	generator->generate(0x335AB);
	generator->generate(0x3369D);
	generator->generate(0x335AC);
	//Arrow Pillar
	generator->generate(0x09DD5);
	//Challenge Entrance
	generator->generate(0x0A16E);
	//Theater Exit
	generator->generate(0x039B4);
	//Town Exit
	generator->generate(0x09E85);
}

void PuzzleList::GenerateOrchardH()
{

}

void PuzzleList::GenerateKeepH()
{
	generator->setLoadingData(L"Keep", 5);
	generator->resetConfig();
	generator->generate(0x033EA);
	generator->generate(0x01BE9);
	generator->generate(0x01CD3);
	generator->generate(0x01D3F);
	generator->generate(0x03317);
	specialCase->clearTarget(0x0360E); //Must solve pressure plate side
}

void PuzzleList::GenerateDesertH() {
	generator->setLoadingData(L"Desert", 69);
	generator->resetConfig();
	/*generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x00698);*/
}