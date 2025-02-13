// This is an open source non-commercial project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Memory.h"
#include "Randomizer.h"
#include "Panels.h"
#include "PuzzleList.h"
#include <string>
#include <iostream>
#include <numeric>
#include "Random.h"
#include "Quaternion.h"

void Randomizer::GenerateNormal(HWND loadingHandle) {
	std::shared_ptr<PuzzleList> puzzles = std::make_shared<PuzzleList>();
	puzzles->setLoadingHandle(loadingHandle);
	puzzles->setSeed(seed, seedIsRNG, colorblind);
	puzzles->GenerateAllN();
}

void Randomizer::GenerateHard(HWND loadingHandle) {
	std::shared_ptr<PuzzleList> puzzles = std::make_shared<PuzzleList>();
	puzzles->setLoadingHandle(loadingHandle);
	puzzles->setSeed(seed, seedIsRNG, colorblind);
	puzzles->GenerateAllH();
	if (!Special::hasBeenRandomized())
		MessageBox(GetActiveWindow(), L"Hi there! Thanks for trying out Expert Mode. It will be tough, but I hope you have fun!\r\n\r\n"
		L"Expert has some unique tricks up its sleeve. You will encounter some situations that may seem impossible at first glance. "
		L"In these situations, try to think of alternate approaches that weren't required in the base game.\r\n\r\n"
		L"For especially tough puzzles, the Solver folder has a solver that works for most puzzles, though it currently has some trouble with Erasers.\r\n\r\n"
		L"The Github wiki also has a Hints page that can help with certain tricky puzzles.\r\n\r\n"
		L"Thanks for playing, and good luck!", L"Welcome", MB_OK);
}

template <class T>
int find(const std::vector<T> &data, T search, size_t startIndex = 0) {
	for (size_t i = startIndex; i<data.size(); i++) {
		if (data[i] == search) return static_cast<int>(i);
	}
	std::cout << "Couldn't find " << search << " in data!" << std::endl;
	throw std::exception("Couldn't find value in data!");
}

void Randomizer::AdjustSpeed() {
<<<<<<< Updated upstream
<<<<<<< HEAD
	_memory->WritePanelData<float>(0x09F95, OPEN_RATE, { 0.04f });  // Desert Surface Final Control, 4x
	_memory->WritePanelData<float>(0x03839, OPEN_RATE, { 0.7f }); // Mill Ramp, 3x
	_memory->WritePanelData<float>(0x021BA, OPEN_RATE, { 1.5f }); // Mill Lift, 3x
	_memory->WritePanelData<float>(0x17CC1, OPEN_RATE, { 0.8f }); // Mill Elevator, 4x
	_memory->WritePanelData<float>(0x0061A, OPEN_RATE, { 0.1f }); // Swamp Sliding Bridge, 4x
	_memory->WritePanelData<float>(0x09EEC, OPEN_RATE, { 0.1f }); // Mountain 2 Elevator, 4x
	_memory->WritePanelData<float>(0x17E74, OPEN_RATE, { 0.03f }); // Swamp Flood gate (inner), 2x //Keeping these slower for now to help with EP's
	_memory->WritePanelData<float>(0x1802C, OPEN_RATE, { 0.03f }); // Swamp Flood gate (outer), 2x
	_memory->WritePanelData<float>(0x005A2, OPEN_RATE, { 0.04f }); // Swamp Rotating Bridge, 4x
	_memory->WritePanelData<float>(0x17C6A, OPEN_RATE, { 0.25f }); // Ramp Angle, 5x
	_memory->WritePanelData<float>(0x17F02, OPEN_RATE, { 0.15f }); // Ramp Position, 4x
	_memory->WritePanelData<float>(0x17C50, OPEN_RATE, { 0.3f }); //Boathouse Barrier, 2x
=======
=======
>>>>>>> Stashed changes
	_memory->WritePanelData<float>(0x09F95, OPEN_RATE, { 9999999.9f });  // Desert Surface Final Control, 4x
	_memory->WritePanelData<float>(0x03839, OPEN_RATE, { 9.9f }); // Mill Ramp, 3x
	_memory->WritePanelData<float>(0x021BA, OPEN_RATE, { 9.9f }); // Mill Lift, 3x
	_memory->WritePanelData<float>(0x17CC1, OPEN_RATE, { 50.69f }); // Mill Elevator, 4x
	_memory->WritePanelData<float>(0x0061A, OPEN_RATE, { 9999999.9f }); // Swamp Sliding Bridge, 4x
	_memory->WritePanelData<float>(0x09EEC, OPEN_RATE, { 9999999.9f }); // Mountain 2 Elevator, 4x
	_memory->WritePanelData<float>(0x17E74, OPEN_RATE, { 9999999.9f }); // Swamp Flood gate (inner), 2x //Keeping these slower for now to help with EP's
	_memory->WritePanelData<float>(0x1802C, OPEN_RATE, { 9999999.9f }); // Swamp Flood gate (outer), 2x
	_memory->WritePanelData<float>(0x005A2, OPEN_RATE, { 9999999.9f }); // Swamp Rotating Bridge, 4x
	_memory->WritePanelData<float>(0x17C6A, OPEN_RATE, { 9999999.9f }); // Ramp Angle, 5x
	_memory->WritePanelData<float>(0x17F02, OPEN_RATE, { 9999999.9f }); // Ramp Position, 4x
	//_memory->WritePanelData<float>(0x0A15C, OPEN_RATE, { 9999999.9f }); // desert elevator, stupid
	//_memory->WritePanelData<float>(0x36343, OPEN_RATE, { 50.9f }); // boat
	//_memory->WritePanelData<float>(0x3645A, OPEN_RATE, { 30.9f }); // boat
	//_memory->WritePanelData<float>(0x3645B, OPEN_RATE, { 30.9f }); // boat
<<<<<<< Updated upstream
>>>>>>> f26508f17fa6ff98c35c3cf3656fc03ec406745f
=======
>>>>>>> Stashed changes
}

void Randomizer::RandomizeDesert() {
	std::vector<int> puzzles = desertPanels;
	std::vector<int> valid1 = { 0x00698, 0x0048F, 0x09F92, 0x09DA6, 0x0078D, 0x04D18, 0x0117A, 0x17ECA, 0x0A02D };
	std::vector<int> valid2 = { 0x00698, 0x09F92, 0x0A036, 0x0A049, 0x0A053, 0x00422, 0x006E3, 0x00C72, 0x008BB, 0x0078D, 0x01205, 0x181AB, 0x012D7, 0x17ECA, 0x0A02D };
	std::vector<int> valid3 = { 0x00698, 0x0048F, 0x09F92, 0x0A036, 0x0A049, 0x00422, 0x008BB, 0x0078D, 0x18313, 0x01205 };
	std::vector<int> validSurfaceSeven = { 0x00698, 0x0048F, 0x09F92, 0x0A036, 0x0A049, 0x0A053, 0x00422, 0x006E3, 0x0A02D, 0x00C72, 0x0129D, 0x008BB, 0x0078D, 0x18313, 0x04D18, 0x01205, 0x181AB, 0x17ECA, 0x012D7 };
	int endIndex = static_cast<int>(desertPanels.size());
	for (int i = 0; i < endIndex - 1; i++) {
		const int target = Random::rand() % (endIndex - i) + i;
		//Prevent ambiguity caused by shadows, and ensure all latches on Surface 7 and Light 3 must be opened
		if (i == target || i == 1 && std::find(valid1.begin(), valid1.end(), desertPanels[target]) == valid1.end() || 
			(i == 2 || i == 9) && std::find(valid2.begin(), valid2.end(), desertPanels[target]) == valid2.end() ||
			i == 6 && std::find(validSurfaceSeven.begin(), validSurfaceSeven.end(), desertPanels[target]) == validSurfaceSeven.end() ||
			i == 10 && std::find(valid3.begin(), valid3.end(), desertPanels[target]) == valid3.end()) {
			i--;
			continue;
		}
		if (i != target) {
			SwapPanels(puzzles[i], puzzles[target], SWAP::LINES);
			std::swap(desertPanels[i], desertPanels[target]);
		}
		_memory->WritePanelData<float>(puzzles[i], PATH_WIDTH_SCALE, { 0.8f });
	}
	/* TODO: Add into v1.3 after doing more experimentation
	if (_memory->ReadPanelData<float>(0x00295, POWER) < 1)
		for (auto panel : desertPanels) {
			auto rotationData = _memory->ReadPanelData<float>(panel, ORIENTATION, 4);
			auto q = Quaternion{rotationData[3], rotationData[0], rotationData[1], rotationData[2]};
			q = q.Rotate90();
			//q = q.Reflect(); Figure this out at some point
			_memory->WritePanelData<float>(panel, ORIENTATION, {(float)q.x, (float)q.y, (float)q.z, (float)q.w});
		}*/
	Special::setPower(0x09F94, false); // Turn off desert surface 8
	Special::setTargetAndDeactivate(0x17ECA, 0x18076); // Change desert floating target to desert flood final
}

void Randomizer::Randomize(std::vector<int>& panels, int flags) {
	return RandomizeRange(panels, flags, 0, panels.size());
}

// Range is [start, end)
void Randomizer::RandomizeRange(std::vector<int> &panels, int flags, size_t startIndex, size_t endIndex) {
	if (panels.size() == 0) return;
	if (startIndex >= endIndex) return;
	if (endIndex >= panels.size()) endIndex = static_cast<int>(panels.size());
	for (size_t i = endIndex - 1; i > startIndex; i--) {
		const int target = (Random::rand() % (static_cast<int>(i) - static_cast<int>(startIndex) + 1)) + static_cast<int>(startIndex);
		if (i != target) {
			SwapPanels(panels[i], panels[target], flags);
			std::swap(panels[i], panels[target]); // Panel indices in the array
		}
	}
}

//Isn't actualy working
void Randomizer::RandomizeAudiologs()
{
	std::vector<int> audiologs = {
		0x3C0F7, 0x3C0FD, 0x32A00, 0x3C0FE, 0x338B0, 0x338B7, 0x338AD,
		0x338A5, 0x338AE, 0x338AF, 0x338A7, 0x338A3, 0x338A4, 0x3C108,
		0x338EF, 0x336E5, 0x338A6, 0x3C100, 0x3C0F4, 0x3C102, 0x3C10D,
		0x3C10E, 0x3C10B, 0x0074F, 0x012C7, 0x329FF, 0x3C106, 0x33AFF,
		0x011F9, 0x00763, 0x32A08, 0x3C101, 0x3C0FF, 0x3C103, 0x00A0F,
		0x339A9, 0x015C0, 0x33B36, 0x3C10C, 0x32A0E, 0x329FE, 0x32A07,
		0x00761, 0x3C109, 0x33B37, 0x3C107, 0x3C0F3, 0x015B7, 0x3C10A,
		0x32A0A, 0x015C1, 0x3C12A, 0x3C104, 0x3C105, 0x339A8, 0x0050A,
		0x338BD, 0x3C135, 0x338C9, 0x338D7, 0x338C1, 0x338CA
	};
	Randomizer::RandomizeRange(audiologs, SWAP::AUDIO_NAMES, 0, audiologs.size());
}

void Randomizer::SwapPanels(int panel1, int panel2, int flags) {
	std::map<int, int> offsets;

	if (flags & SWAP::TARGETS) {
		offsets[TARGET] = sizeof(int);
	}
	if (flags & SWAP::AUDIO_NAMES) {
		offsets[AUDIO_LOG_NAME] = sizeof(void*); //This isn't actually working 
	}
	if (flags & SWAP::COLORS) {
		offsets[PATH_COLOR] = 16;
		offsets[REFLECTION_PATH_COLOR] = 16;
		offsets[DOT_COLOR] = 16;
		offsets[ACTIVE_COLOR] = 16;
		offsets[BACKGROUND_REGION_COLOR] = 12; // Not copying alpha to preserve transparency.
		offsets[SUCCESS_COLOR_A] = 16;
		offsets[SUCCESS_COLOR_B] = 16;
		offsets[STROBE_COLOR_A] = 16;
		offsets[STROBE_COLOR_B] = 16;
		offsets[ERROR_COLOR] = 16;
		offsets[PATTERN_POINT_COLOR] = 16;
		offsets[PATTERN_POINT_COLOR_A] = 16;
		offsets[PATTERN_POINT_COLOR_B] = 16;
		offsets[SYMBOL_A] = 16;
		offsets[SYMBOL_B] = 16;
		offsets[SYMBOL_C] = 16;
		offsets[SYMBOL_D] = 16;
		offsets[SYMBOL_E] = 16;
		offsets[PUSH_SYMBOL_COLORS] = sizeof(int);
		offsets[OUTER_BACKGROUND] = 16;
		offsets[OUTER_BACKGROUND_MODE] = sizeof(int);
		offsets[NUM_COLORED_REGIONS] = sizeof(int);
		offsets[COLORED_REGIONS] = sizeof(void*);
	}
	if (flags & SWAP::LINES) {
		offsets[AUDIO_PREFIX] = sizeof(void*);
		offsets[PATH_WIDTH_SCALE] = sizeof(float);
		offsets[STARTPOINT_SCALE] = sizeof(float);
		offsets[NUM_DOTS] = sizeof(int);
		offsets[NUM_CONNECTIONS] = sizeof(int);
		offsets[DOT_POSITIONS] = sizeof(void*);
		offsets[DOT_FLAGS] = sizeof(void*);
		offsets[DOT_CONNECTION_A] = sizeof(void*);
		offsets[DOT_CONNECTION_B] = sizeof(void*);
		offsets[DECORATIONS] = sizeof(void*);
		offsets[DECORATION_FLAGS] = sizeof(void*);
		offsets[DECORATION_COLORS] = sizeof(void*);
		offsets[NUM_DECORATIONS] = sizeof(int);
		offsets[REFLECTION_DATA] = sizeof(void*);
		offsets[GRID_SIZE_X] = sizeof(int);
		offsets[GRID_SIZE_Y] = sizeof(int);
		offsets[STYLE_FLAGS] = sizeof(int);
		offsets[SEQUENCE_LEN] = sizeof(int);
		offsets[SEQUENCE] = sizeof(void*);
		offsets[DOT_SEQUENCE_LEN] = sizeof(int);
		offsets[DOT_SEQUENCE] = sizeof(void*);
		offsets[DOT_SEQUENCE_LEN_REFLECTION] = sizeof(int);
		offsets[DOT_SEQUENCE_REFLECTION] = sizeof(void*);
		offsets[PANEL_TARGET] = sizeof(void*);
		offsets[SPECULAR_TEXTURE] = sizeof(void*);
	}

	for (auto const&[offset, size] : offsets) {
		std::vector<byte> panel1data = _memory->ReadPanelData<byte>(panel1, offset, size);
		std::vector<byte> panel2data = _memory->ReadPanelData<byte>(panel2, offset, size);
		_memory->WritePanelData<byte>(panel2, offset, panel1data);
		_memory->WritePanelData<byte>(panel1, offset, panel2data);
	}
	_memory->WritePanelData<int>(panel1, NEEDS_REDRAW, { 1 });
	_memory->WritePanelData<int>(panel2, NEEDS_REDRAW, { 1 });
}
