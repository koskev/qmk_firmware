// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_HAND_PIN D4 // GP3 on rp2040
#define SPLIT_HAND_PIN_LOW_IS_LEFT

#ifdef ENCODER_RESOLUTION
#    undef ENCODER_RESOLUTION
#endif // ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4
