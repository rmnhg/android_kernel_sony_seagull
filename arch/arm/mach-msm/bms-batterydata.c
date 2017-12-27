/* Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 * Copyright (C) 2011-2013 Foxconn International Holdings, Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/batterydata-lib.h>

//CORE-DL-ImportBatData-00 +[
#ifdef ORIGINAL_VERSION
static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 65},
	.y		= {1492, 1492, 1493, 1483, 1502},
	.cols	= 5
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.ocv		= {
				{4173, 4167, 4163, 4156, 4154},
				{4104, 4107, 4108, 4102, 4104},
				{4057, 4072, 4069, 4061, 4060},
				{3973, 4009, 4019, 4016, 4020},
				{3932, 3959, 3981, 3982, 3983},
				{3899, 3928, 3954, 3950, 3950},
				{3868, 3895, 3925, 3921, 3920},
				{3837, 3866, 3898, 3894, 3892},
				{3812, 3841, 3853, 3856, 3862},
				{3794, 3818, 3825, 3823, 3822},
				{3780, 3799, 3804, 3804, 3803},
				{3768, 3787, 3790, 3788, 3788},
				{3757, 3779, 3778, 3775, 3776},
				{3747, 3772, 3771, 3766, 3765},
				{3736, 3763, 3766, 3760, 3746},
				{3725, 3749, 3756, 3747, 3729},
				{3714, 3718, 3734, 3724, 3706},
				{3701, 3703, 3696, 3689, 3668},
				{3675, 3695, 3682, 3675, 3662},
				{3670, 3691, 3680, 3673, 3661},
				{3661, 3686, 3679, 3672, 3656},
				{3649, 3680, 3676, 3669, 3641},
				{3633, 3669, 3667, 3655, 3606},
				{3610, 3647, 3640, 3620, 3560},
				{3580, 3607, 3596, 3572, 3501},
				{3533, 3548, 3537, 3512, 3425},
				{3457, 3468, 3459, 3429, 3324},
				{3328, 3348, 3340, 3297, 3172},
				{3000, 3000, 3000, 3000, 3000}
	}
};

static struct sf_lut rbatt_sf = {
	.rows		= 29,
	.cols		= 5,
	/* row_entries are temperature */
	.row_entries	= {-20, 0, 20, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.sf		= {
				{357, 187, 100, 91, 91},
				{400, 208, 105, 94, 94},
				{390, 204, 106, 95, 96},
				{391, 201, 108, 98, 98},
				{391, 202, 110, 98, 100},
				{390, 200, 110, 99, 102},
				{389, 200, 110, 99, 102},
				{393, 202, 101, 93, 100},
				{407, 205, 99, 89, 94},
				{428, 208, 100, 91, 96},
				{455, 212, 102, 92, 98},
				{495, 220, 104, 93, 101},
				{561, 232, 107, 95, 102},
				{634, 245, 112, 98, 98},
				{714, 258, 114, 98, 98},
				{791, 266, 114, 97, 100},
				{871, 289, 108, 95, 97},
				{973, 340, 124, 108, 105},
				{489, 241, 109, 96, 99},
				{511, 246, 110, 96, 99},
				{534, 252, 111, 95, 98},
				{579, 263, 112, 96, 96},
				{636, 276, 111, 95, 97},
				{730, 294, 109, 96, 99},
				{868, 328, 112, 98, 104},
				{1089, 374, 119, 101, 115},
				{1559, 457, 128, 105, 213},
				{12886, 1026, 637, 422, 3269},
				{170899, 127211, 98968, 88907, 77102},
	}
};

struct bms_battery_data palladium_1500_data = {
	.fcc			= 1500,
	.fcc_temp_lut		= &fcc_temp,
	.pc_temp_ocv_lut	= &pc_temp_ocv,
	.rbatt_sf_lut		= &rbatt_sf,
	.default_rbatt_mohm	= 236,
	.rbatt_capacitive_mohm	= 50,
	.flat_ocv_threshold_uv	= 3800000,
};
#else
static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 50, 60},
	.y		= {2552, 2603, 2581, 2574, 2524},
	.cols	= 5
};

static struct sf_lut rbatt_sf = {
	.rows		= 29,
	.cols		= 5,
	.row_entries		= {-20, 0, 25, 50, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.sf		= {
				{758, 357, 100, 65, 63},
				{758, 357, 100, 65, 63},
				{726, 357, 101, 67, 64},
				{706, 356, 103, 67, 65},
				{698, 356, 106, 69, 66},
				{695, 353, 110, 70, 67},
				{699, 349, 113, 73, 70},
				{707, 345, 112, 75, 71},
				{717, 346, 108, 72, 70},
				{730, 352, 105, 70, 67},
				{746, 362, 106, 69, 68},
				{767, 374, 109, 71, 69},
				{790, 386, 112, 72, 70},
				{819, 400, 116, 74, 72},
				{856, 419, 118, 74, 72},
				{903, 442, 119, 72, 72},
				{1018, 472, 121, 73, 72},
				{1332, 515, 124, 74, 72},
				{1274, 513, 120, 75, 73},
				{1446, 538, 121, 75, 74},
				{1670, 567, 123, 76, 75},
				{1992, 600, 125, 77, 76},
				{2449, 638, 125, 77, 74},
				{3150, 683, 125, 76, 74},
				{4243, 740, 127, 77, 75},
				{6134, 913, 131, 78, 76},
				{9698, 1370, 137, 80, 78},
				{17662, 2407, 151, 88, 85},
				{36917, 6992, 14376, 246, 245}
	}
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 50, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4300, 4304, 4307, 4293, 4299},
				{4165, 4207, 4237, 4233, 4239},
				{4088, 4143, 4181, 4180, 4187},
				{4023, 4086, 4128, 4129, 4136},
				{3967, 4034, 4079, 4080, 4088},
				{3919, 3984, 4033, 4035, 4043},
				{3879, 3934, 3989, 3993, 4000},
				{3843, 3889, 3946, 3951, 3959},
				{3810, 3851, 3902, 3907, 3914},
				{3782, 3821, 3865, 3870, 3876},
				{3755, 3798, 3837, 3842, 3848},
				{3732, 3778, 3814, 3820, 3825},
				{3712, 3760, 3796, 3801, 3805},
				{3693, 3743, 3780, 3784, 3786},
				{3675, 3726, 3764, 3761, 3759},
				{3657, 3707, 3745, 3735, 3730},
				{3638, 3681, 3722, 3713, 3708},
				{3611, 3644, 3691, 3686, 3682},
				{3575, 3606, 3665, 3665, 3661},
				{3564, 3598, 3662, 3662, 3657},
				{3548, 3588, 3658, 3657, 3652},
				{3530, 3576, 3650, 3647, 3640},
				{3506, 3559, 3631, 3623, 3613},
				{3477, 3533, 3596, 3585, 3574},
				{3439, 3490, 3547, 3537, 3525},
				{3385, 3429, 3486, 3475, 3464},
				{3309, 3345, 3405, 3392, 3382},
				{3198, 3217, 3281, 3270, 3258},
				{3000, 3000, 3000, 3000, 3000}
	}
};

struct bms_battery_data palladium_1500_data = {
	.fcc				= 2500,
	.fcc_temp_lut			= &fcc_temp,
	.pc_temp_ocv_lut		= &pc_temp_ocv,
	.rbatt_sf_lut			= &rbatt_sf,
	.default_rbatt_mohm	= 240,
};
#endif
//CORE-DL-ImportBatData-00 +]
