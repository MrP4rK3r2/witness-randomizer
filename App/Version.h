#pragma once

#define TO_STRING2(s) #s
#define TO_STRING(s) TO_STRING2(s)

#define MAJOR 1
<<<<<<< Updated upstream
<<<<<<< HEAD
#define MINOR 2
#define PATCH 3
=======
#define MINOR 0
=======
#define MINOR 0
<<<<<<< HEAD
#define PATCH 0
=======
>>>>>>> Stashed changes
#define PATCH 1
>>>>>>> f26508f17fa6ff98c35c3cf3656fc03ec406745f

#define VERSION_STR     TO_STRING(MAJOR) "." TO_STRING(MINOR) "." TO_STRING(PATCH)
#define VERSION			MAJOR, MINOR, PATCH

#define PRODUCT_NAME L"Witness Random Puzzle Generator"
#define WINDOW_CLASS L"WitnessRandomizer"
