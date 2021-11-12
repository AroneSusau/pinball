#pragma once

#include "Common.h"

const glm::vec3 generic_cube[36] = {
	
	// Front
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(-1.0f, 1.0f, -1.0f),
	glm::vec3(1.0f, 1.0f, -1.0f),

	glm::vec3(1.0f, 1.0f, -1.0f),
	glm::vec3(1.0f, -1.0f, -1.0f),
	glm::vec3(-1.0f, -1.0f, -1.0f),

	// Back
	glm::vec3(-1.0f, -1.0f, 1.0f),
	glm::vec3(-1.0f, 1.0f, 1.0f),
	glm::vec3(1.0f, 1.0f, 1.0f),

	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(1.0f, -1.0f, 1.0f),
	glm::vec3(-1.0f, -1.0f, 1.0f),

	// Left
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(-1.0f, -1.0f, 1.0f),
	glm::vec3(-1.0f, 1.0f, 1.0f),

	glm::vec3(-1.0f, 1.0f, 1.0f),
	glm::vec3(-1.0f, 1.0f, -1.0f),
	glm::vec3(-1.0f, -1.0f, -1.0f),

	// Right
	glm::vec3(1.0f, -1.0f, -1.0f),
	glm::vec3(1.0f, -1.0f, 1.0f),
	glm::vec3(1.0f, 1.0f, 1.0f),

	glm::vec3(1.0f, 1.0f, 1.0f),
	glm::vec3(1.0f, 1.0f, -1.0f),
	glm::vec3(1.0f, -1.0f, -1.0f),

	// Top
	glm::vec3(-1.0f, 1.0f, -1.0f),
	glm::vec3(1.0f,  1.0f, -1.0f),
	glm::vec3(1.0f,  1.0f,  1.0f),

	glm::vec3(1.0f,  1.0f,  1.0f),
	glm::vec3(-1.0f, 1.0f,  1.0f),
	glm::vec3(-1.0f, 1.0f, -1.0f),

	// Bottom
	glm::vec3(-1.0f, -1.0f, -1.0f),
	glm::vec3(1.0f,  -1.0f, -1.0f),
	glm::vec3(1.0f,  -1.0f,  1.0f),

	glm::vec3(1.0f,  -1.0f,  1.0f),
	glm::vec3(-1.0f, -1.0f,  1.0f),
	glm::vec3(-1.0f, -1.0f, -1.0f),
};

const glm::vec3 generic_sphere[] = {
	glm::vec3(-1.76816e-06, -1.28465e-06, 50),
	glm::vec3(15.4508, 0, 47.5528),
	glm::vec3(12.5, 9.08178, 47.5528),
	glm::vec3(-6.75378e-07, -2.0786e-06, 50),
	glm::vec3(12.5, 9.08178, 47.5528),
	glm::vec3(4.77457, 14.6946, 47.5528),
	glm::vec3(6.75378e-07, -2.0786e-06, 50),
	glm::vec3(4.77457, 14.6946, 47.5528),
	glm::vec3(-4.77458, 14.6946, 47.5528),
	glm::vec3(1.76816e-06, -1.28465e-06, 50),
	glm::vec3(-4.77458, 14.6946, 47.5528),
	glm::vec3(-12.5, 9.08178, 47.5528),
	glm::vec3(2.18557e-06, 1.91069e-13, 50),
	glm::vec3(-12.5, 9.08178, 47.5528),
	glm::vec3(-15.4508, -1.35076e-06, 47.5528),
	glm::vec3(1.76816e-06, 1.28465e-06, 50),
	glm::vec3(-15.4508, -1.35076e-06, 47.5528),
	glm::vec3(-12.5, -9.08178, 47.5528),
	glm::vec3(6.75378e-07, 2.0786e-06, 50),
	glm::vec3(-12.5, -9.08178, 47.5528),
	glm::vec3(-4.77458, -14.6946, 47.5528),
	glm::vec3(-6.75378e-07, 2.0786e-06, 50),
	glm::vec3(-4.77458, -14.6946, 47.5528),
	glm::vec3(4.77458, -14.6946, 47.5528),
	glm::vec3(-1.76816e-06, 1.28464e-06, 50),
	glm::vec3(4.77458, -14.6946, 47.5528),
	glm::vec3(12.5, -9.08178, 47.5528),
	glm::vec3(-2.18557e-06, -3.82137e-13, 50),
	glm::vec3(12.5, -9.08178, 47.5528),
	glm::vec3(15.4508, 2.70151e-06, 47.5528),
	glm::vec3(15.4508, 0, 47.5528),
	glm::vec3(29.3893, 0, 40.4509),
	glm::vec3(12.5, 9.08178, 47.5528),
	glm::vec3(12.5, 9.08178, 47.5528),
	glm::vec3(29.3893, 0, 40.4509),
	glm::vec3(23.7764, 17.2746, 40.4509),
	glm::vec3(12.5, 9.08178, 47.5528),
	glm::vec3(23.7764, 17.2746, 40.4509),
	glm::vec3(4.77457, 14.6946, 47.5528),
	glm::vec3(4.77457, 14.6946, 47.5528),
	glm::vec3(23.7764, 17.2746, 40.4509),
	glm::vec3(9.08178, 27.9509, 40.4509),
	glm::vec3(4.77457, 14.6946, 47.5528),
	glm::vec3(9.08178, 27.9509, 40.4509),
	glm::vec3(-4.77458, 14.6946, 47.5528),
	glm::vec3(-4.77458, 14.6946, 47.5528),
	glm::vec3(9.08178, 27.9509, 40.4509),
	glm::vec3(-9.08178, 27.9509, 40.4509),
	glm::vec3(-4.77458, 14.6946, 47.5528),
	glm::vec3(-9.08178, 27.9509, 40.4509),
	glm::vec3(-12.5, 9.08178, 47.5528),
	glm::vec3(-12.5, 9.08178, 47.5528),
	glm::vec3(-9.08178, 27.9509, 40.4509),
	glm::vec3(-23.7764, 17.2746, 40.4509),
	glm::vec3(-12.5, 9.08178, 47.5528),
	glm::vec3(-23.7764, 17.2746, 40.4509),
	glm::vec3(-15.4508, -1.35076e-06, 47.5528),
	glm::vec3(-15.4508, -1.35076e-06, 47.5528),
	glm::vec3(-23.7764, 17.2746, 40.4509),
	glm::vec3(-29.3893, -2.56929e-06, 40.4509),
	glm::vec3(-15.4508, -1.35076e-06, 47.5528),
	glm::vec3(-29.3893, -2.56929e-06, 40.4509),
	glm::vec3(-12.5, -9.08178, 47.5528),
	glm::vec3(-12.5, -9.08178, 47.5528),
	glm::vec3(-29.3893, -2.56929e-06, 40.4509),
	glm::vec3(-23.7764, -17.2746, 40.4509),
	glm::vec3(-12.5, -9.08178, 47.5528),
	glm::vec3(-23.7764, -17.2746, 40.4509),
	glm::vec3(-4.77458, -14.6946, 47.5528),
	glm::vec3(-4.77458, -14.6946, 47.5528),
	glm::vec3(-23.7764, -17.2746, 40.4509),
	glm::vec3(-9.08179, -27.9509, 40.4509),
	glm::vec3(-4.77458, -14.6946, 47.5528),
	glm::vec3(-9.08179, -27.9509, 40.4509),
	glm::vec3(4.77458, -14.6946, 47.5528),
	glm::vec3(4.77458, -14.6946, 47.5528),
	glm::vec3(-9.08179, -27.9509, 40.4509),
	glm::vec3(9.08179, -27.9509, 40.4509),
	glm::vec3(4.77458, -14.6946, 47.5528),
	glm::vec3(9.08179, -27.9509, 40.4509),
	glm::vec3(12.5, -9.08178, 47.5528),
	glm::vec3(12.5, -9.08178, 47.5528),
	glm::vec3(9.08179, -27.9509, 40.4509),
	glm::vec3(23.7764, -17.2746, 40.4509),
	glm::vec3(12.5, -9.08178, 47.5528),
	glm::vec3(23.7764, -17.2746, 40.4509),
	glm::vec3(15.4508, 2.70151e-06, 47.5528),
	glm::vec3(15.4508, 2.70151e-06, 47.5528),
	glm::vec3(23.7764, -17.2746, 40.4509),
	glm::vec3(29.3893, 5.13858e-06, 40.4509),
	glm::vec3(29.3893, 0, 40.4509),
	glm::vec3(40.4509, 0, 29.3893),
	glm::vec3(23.7764, 17.2746, 40.4509),
	glm::vec3(23.7764, 17.2746, 40.4509),
	glm::vec3(40.4509, 0, 29.3893),
	glm::vec3(32.7254, 23.7764, 29.3893),
	glm::vec3(23.7764, 17.2746, 40.4509),
	glm::vec3(32.7254, 23.7764, 29.3893),
	glm::vec3(9.08178, 27.9509, 40.4509),
	glm::vec3(9.08178, 27.9509, 40.4509),
	glm::vec3(32.7254, 23.7764, 29.3893),
	glm::vec3(12.5, 38.471, 29.3893),
	glm::vec3(9.08178, 27.9509, 40.4509),
	glm::vec3(12.5, 38.471, 29.3893),
	glm::vec3(-9.08178, 27.9509, 40.4509),
	glm::vec3(-9.08178, 27.9509, 40.4509),
	glm::vec3(12.5, 38.471, 29.3893),
	glm::vec3(-12.5, 38.471, 29.3893),
	glm::vec3(-9.08178, 27.9509, 40.4509),
	glm::vec3(-12.5, 38.471, 29.3893),
	glm::vec3(-23.7764, 17.2746, 40.4509),
	glm::vec3(-23.7764, 17.2746, 40.4509),
	glm::vec3(-12.5, 38.471, 29.3893),
	glm::vec3(-32.7254, 23.7764, 29.3893),
	glm::vec3(-23.7764, 17.2746, 40.4509),
	glm::vec3(-32.7254, 23.7764, 29.3893),
	glm::vec3(-29.3893, -2.56929e-06, 40.4509),
	glm::vec3(-29.3893, -2.56929e-06, 40.4509),
	glm::vec3(-32.7254, 23.7764, 29.3893),
	glm::vec3(-40.4509, -3.53633e-06, 29.3893),
	glm::vec3(-29.3893, -2.56929e-06, 40.4509),
	glm::vec3(-40.4509, -3.53633e-06, 29.3893),
	glm::vec3(-23.7764, -17.2746, 40.4509),
	glm::vec3(-23.7764, -17.2746, 40.4509),
	glm::vec3(-40.4509, -3.53633e-06, 29.3893),
	glm::vec3(-32.7254, -23.7764, 29.3893),
	glm::vec3(-23.7764, -17.2746, 40.4509),
	glm::vec3(-32.7254, -23.7764, 29.3893),
	glm::vec3(-9.08179, -27.9509, 40.4509),
	glm::vec3(-9.08179, -27.9509, 40.4509),
	glm::vec3(-32.7254, -23.7764, 29.3893),
	glm::vec3(-12.5, -38.471, 29.3893),
	glm::vec3(-9.08179, -27.9509, 40.4509),
	glm::vec3(-12.5, -38.471, 29.3893),
	glm::vec3(9.08179, -27.9509, 40.4509),
	glm::vec3(9.08179, -27.9509, 40.4509),
	glm::vec3(-12.5, -38.471, 29.3893),
	glm::vec3(12.5, -38.471, 29.3893),
	glm::vec3(9.08179, -27.9509, 40.4509),
	glm::vec3(12.5, -38.471, 29.3893),
	glm::vec3(23.7764, -17.2746, 40.4509),
	glm::vec3(23.7764, -17.2746, 40.4509),
	glm::vec3(12.5, -38.471, 29.3893),
	glm::vec3(32.7254, -23.7764, 29.3893),
	glm::vec3(23.7764, -17.2746, 40.4509),
	glm::vec3(32.7254, -23.7764, 29.3893),
	glm::vec3(29.3893, 5.13858e-06, 40.4509),
	glm::vec3(29.3893, 5.13858e-06, 40.4509),
	glm::vec3(32.7254, -23.7764, 29.3893),
	glm::vec3(40.4509, 7.07265e-06, 29.3893),
	glm::vec3(40.4509, 0, 29.3893),
	glm::vec3(47.5528, 0, 15.4508),
	glm::vec3(32.7254, 23.7764, 29.3893),
	glm::vec3(32.7254, 23.7764, 29.3893),
	glm::vec3(47.5528, 0, 15.4508),
	glm::vec3(38.471, 27.9508, 15.4508),
	glm::vec3(32.7254, 23.7764, 29.3893),
	glm::vec3(38.471, 27.9508, 15.4508),
	glm::vec3(12.5, 38.471, 29.3893),
	glm::vec3(12.5, 38.471, 29.3893),
	glm::vec3(38.471, 27.9508, 15.4508),
	glm::vec3(14.6946, 45.2254, 15.4508),
	glm::vec3(12.5, 38.471, 29.3893),
	glm::vec3(14.6946, 45.2254, 15.4508),
	glm::vec3(-12.5, 38.471, 29.3893),
	glm::vec3(-12.5, 38.471, 29.3893),
	glm::vec3(14.6946, 45.2254, 15.4508),
	glm::vec3(-14.6946, 45.2254, 15.4508),
	glm::vec3(-12.5, 38.471, 29.3893),
	glm::vec3(-14.6946, 45.2254, 15.4508),
	glm::vec3(-32.7254, 23.7764, 29.3893),
	glm::vec3(-32.7254, 23.7764, 29.3893),
	glm::vec3(-14.6946, 45.2254, 15.4508),
	glm::vec3(-38.471, 27.9508, 15.4508),
	glm::vec3(-32.7254, 23.7764, 29.3893),
	glm::vec3(-38.471, 27.9508, 15.4508),
	glm::vec3(-40.4509, -3.53633e-06, 29.3893),
	glm::vec3(-40.4509, -3.53633e-06, 29.3893),
	glm::vec3(-38.471, 27.9508, 15.4508),
	glm::vec3(-47.5528, -4.1572e-06, 15.4508),
	glm::vec3(-40.4509, -3.53633e-06, 29.3893),
	glm::vec3(-47.5528, -4.1572e-06, 15.4508),
	glm::vec3(-32.7254, -23.7764, 29.3893),
	glm::vec3(-32.7254, -23.7764, 29.3893),
	glm::vec3(-47.5528, -4.1572e-06, 15.4508),
	glm::vec3(-38.471, -27.9509, 15.4508),
	glm::vec3(-32.7254, -23.7764, 29.3893),
	glm::vec3(-38.471, -27.9509, 15.4508),
	glm::vec3(-12.5, -38.471, 29.3893),
	glm::vec3(-12.5, -38.471, 29.3893),
	glm::vec3(-38.471, -27.9509, 15.4508),
	glm::vec3(-14.6946, -45.2254, 15.4508),
	glm::vec3(-12.5, -38.471, 29.3893),
	glm::vec3(-14.6946, -45.2254, 15.4508),
	glm::vec3(12.5, -38.471, 29.3893),
	glm::vec3(12.5, -38.471, 29.3893),
	glm::vec3(-14.6946, -45.2254, 15.4508),
	glm::vec3(14.6946, -45.2254, 15.4508),
	glm::vec3(12.5, -38.471, 29.3893),
	glm::vec3(14.6946, -45.2254, 15.4508),
	glm::vec3(32.7254, -23.7764, 29.3893),
	glm::vec3(32.7254, -23.7764, 29.3893),
	glm::vec3(14.6946, -45.2254, 15.4508),
	glm::vec3(38.4711, -27.9508, 15.4508),
	glm::vec3(32.7254, -23.7764, 29.3893),
	glm::vec3(38.4711, -27.9508, 15.4508),
	glm::vec3(40.4509, 7.07265e-06, 29.3893),
	glm::vec3(40.4509, 7.07265e-06, 29.3893),
	glm::vec3(38.4711, -27.9508, 15.4508),
	glm::vec3(47.5528, 8.3144e-06, 15.4508),
	glm::vec3(47.5528, 0, 15.4508),
	glm::vec3(50, 0, -2.18557e-06),
	glm::vec3(38.471, 27.9508, 15.4508),
	glm::vec3(38.471, 27.9508, 15.4508),
	glm::vec3(50, 0, -2.18557e-06),
	glm::vec3(40.4509, 29.3893, -2.18557e-06),
	glm::vec3(38.471, 27.9508, 15.4508),
	glm::vec3(40.4509, 29.3893, -2.18557e-06),
	glm::vec3(14.6946, 45.2254, 15.4508),
	glm::vec3(14.6946, 45.2254, 15.4508),
	glm::vec3(40.4509, 29.3893, -2.18557e-06),
	glm::vec3(15.4508, 47.5528, -2.18557e-06),
	glm::vec3(14.6946, 45.2254, 15.4508),
	glm::vec3(15.4508, 47.5528, -2.18557e-06),
	glm::vec3(-14.6946, 45.2254, 15.4508),
	glm::vec3(-14.6946, 45.2254, 15.4508),
	glm::vec3(15.4508, 47.5528, -2.18557e-06),
	glm::vec3(-15.4509, 47.5528, -2.18557e-06),
	glm::vec3(-14.6946, 45.2254, 15.4508),
	glm::vec3(-15.4509, 47.5528, -2.18557e-06),
	glm::vec3(-38.471, 27.9508, 15.4508),
	glm::vec3(-38.471, 27.9508, 15.4508),
	glm::vec3(-15.4509, 47.5528, -2.18557e-06),
	glm::vec3(-40.4509, 29.3893, -2.18557e-06),
	glm::vec3(-38.471, 27.9508, 15.4508),
	glm::vec3(-40.4509, 29.3893, -2.18557e-06),
	glm::vec3(-47.5528, -4.1572e-06, 15.4508),
	glm::vec3(-47.5528, -4.1572e-06, 15.4508),
	glm::vec3(-40.4509, 29.3893, -2.18557e-06),
	glm::vec3(-50, -4.37114e-06, -2.18557e-06),
	glm::vec3(-47.5528, -4.1572e-06, 15.4508),
	glm::vec3(-50, -4.37114e-06, -2.18557e-06),
	glm::vec3(-38.471, -27.9509, 15.4508),
	glm::vec3(-38.471, -27.9509, 15.4508),
	glm::vec3(-50, -4.37114e-06, -2.18557e-06),
	glm::vec3(-40.4508, -29.3893, -2.18557e-06),
	glm::vec3(-38.471, -27.9509, 15.4508),
	glm::vec3(-40.4508, -29.3893, -2.18557e-06),
	glm::vec3(-14.6946, -45.2254, 15.4508),
	glm::vec3(-14.6946, -45.2254, 15.4508),
	glm::vec3(-40.4508, -29.3893, -2.18557e-06),
	glm::vec3(-15.4509, -47.5528, -2.18557e-06),
	glm::vec3(-14.6946, -45.2254, 15.4508),
	glm::vec3(-15.4509, -47.5528, -2.18557e-06),
	glm::vec3(14.6946, -45.2254, 15.4508),
	glm::vec3(14.6946, -45.2254, 15.4508),
	glm::vec3(-15.4509, -47.5528, -2.18557e-06),
	glm::vec3(15.4509, -47.5528, -2.18557e-06),
	glm::vec3(14.6946, -45.2254, 15.4508),
	glm::vec3(15.4509, -47.5528, -2.18557e-06),
	glm::vec3(38.4711, -27.9508, 15.4508),
	glm::vec3(38.4711, -27.9508, 15.4508),
	glm::vec3(15.4509, -47.5528, -2.18557e-06),
	glm::vec3(40.4509, -29.3892, -2.18557e-06),
	glm::vec3(38.4711, -27.9508, 15.4508),
	glm::vec3(40.4509, -29.3892, -2.18557e-06),
	glm::vec3(47.5528, 8.3144e-06, 15.4508),
	glm::vec3(47.5528, 8.3144e-06, 15.4508),
	glm::vec3(40.4509, -29.3892, -2.18557e-06),
	glm::vec3(50, 8.74228e-06, -2.18557e-06),
	glm::vec3(50, 0, -2.18557e-06),
	glm::vec3(47.5528, 0, -15.4509),
	glm::vec3(40.4509, 29.3893, -2.18557e-06),
	glm::vec3(40.4509, 29.3893, -2.18557e-06),
	glm::vec3(47.5528, 0, -15.4509),
	glm::vec3(38.471, 27.9508, -15.4509),
	glm::vec3(40.4509, 29.3893, -2.18557e-06),
	glm::vec3(38.471, 27.9508, -15.4509),
	glm::vec3(15.4508, 47.5528, -2.18557e-06),
	glm::vec3(15.4508, 47.5528, -2.18557e-06),
	glm::vec3(38.471, 27.9508, -15.4509),
	glm::vec3(14.6946, 45.2254, -15.4509),
	glm::vec3(15.4508, 47.5528, -2.18557e-06),
	glm::vec3(14.6946, 45.2254, -15.4509),
	glm::vec3(-15.4509, 47.5528, -2.18557e-06),
	glm::vec3(-15.4509, 47.5528, -2.18557e-06),
	glm::vec3(14.6946, 45.2254, -15.4509),
	glm::vec3(-14.6946, 45.2254, -15.4509),
	glm::vec3(-15.4509, 47.5528, -2.18557e-06),
	glm::vec3(-14.6946, 45.2254, -15.4509),
	glm::vec3(-40.4509, 29.3893, -2.18557e-06),
	glm::vec3(-40.4509, 29.3893, -2.18557e-06),
	glm::vec3(-14.6946, 45.2254, -15.4509),
	glm::vec3(-38.471, 27.9508, -15.4509),
	glm::vec3(-40.4509, 29.3893, -2.18557e-06),
	glm::vec3(-38.471, 27.9508, -15.4509),
	glm::vec3(-50, -4.37114e-06, -2.18557e-06),
	glm::vec3(-50, -4.37114e-06, -2.18557e-06),
	glm::vec3(-38.471, 27.9508, -15.4509),
	glm::vec3(-47.5528, -4.1572e-06, -15.4509),
	glm::vec3(-50, -4.37114e-06, -2.18557e-06),
	glm::vec3(-47.5528, -4.1572e-06, -15.4509),
	glm::vec3(-40.4508, -29.3893, -2.18557e-06),
	glm::vec3(-40.4508, -29.3893, -2.18557e-06),
	glm::vec3(-47.5528, -4.1572e-06, -15.4509),
	glm::vec3(-38.471, -27.9509, -15.4509),
	glm::vec3(-40.4508, -29.3893, -2.18557e-06),
	glm::vec3(-38.471, -27.9509, -15.4509),
	glm::vec3(-15.4509, -47.5528, -2.18557e-06),
	glm::vec3(-15.4509, -47.5528, -2.18557e-06),
	glm::vec3(-38.471, -27.9509, -15.4509),
	glm::vec3(-14.6946, -45.2254, -15.4509),
	glm::vec3(-15.4509, -47.5528, -2.18557e-06),
	glm::vec3(-14.6946, -45.2254, -15.4509),
	glm::vec3(15.4509, -47.5528, -2.18557e-06),
	glm::vec3(15.4509, -47.5528, -2.18557e-06),
	glm::vec3(-14.6946, -45.2254, -15.4509),
	glm::vec3(14.6946, -45.2254, -15.4509),
	glm::vec3(15.4509, -47.5528, -2.18557e-06),
	glm::vec3(14.6946, -45.2254, -15.4509),
	glm::vec3(40.4509, -29.3892, -2.18557e-06),
	glm::vec3(40.4509, -29.3892, -2.18557e-06),
	glm::vec3(14.6946, -45.2254, -15.4509),
	glm::vec3(38.4711, -27.9508, -15.4509),
	glm::vec3(40.4509, -29.3892, -2.18557e-06),
	glm::vec3(38.4711, -27.9508, -15.4509),
	glm::vec3(50, 8.74228e-06, -2.18557e-06),
	glm::vec3(50, 8.74228e-06, -2.18557e-06),
	glm::vec3(38.4711, -27.9508, -15.4509),
	glm::vec3(47.5528, 8.3144e-06, -15.4509),
	glm::vec3(47.5528, 0, -15.4509),
	glm::vec3(40.4509, 0, -29.3893),
	glm::vec3(38.471, 27.9508, -15.4509),
	glm::vec3(38.471, 27.9508, -15.4509),
	glm::vec3(40.4509, 0, -29.3893),
	glm::vec3(32.7254, 23.7764, -29.3893),
	glm::vec3(38.471, 27.9508, -15.4509),
	glm::vec3(32.7254, 23.7764, -29.3893),
	glm::vec3(14.6946, 45.2254, -15.4509),
	glm::vec3(14.6946, 45.2254, -15.4509),
	glm::vec3(32.7254, 23.7764, -29.3893),
	glm::vec3(12.5, 38.471, -29.3893),
	glm::vec3(14.6946, 45.2254, -15.4509),
	glm::vec3(12.5, 38.471, -29.3893),
	glm::vec3(-14.6946, 45.2254, -15.4509),
	glm::vec3(-14.6946, 45.2254, -15.4509),
	glm::vec3(12.5, 38.471, -29.3893),
	glm::vec3(-12.5, 38.471, -29.3893),
	glm::vec3(-14.6946, 45.2254, -15.4509),
	glm::vec3(-12.5, 38.471, -29.3893),
	glm::vec3(-38.471, 27.9508, -15.4509),
	glm::vec3(-38.471, 27.9508, -15.4509),
	glm::vec3(-12.5, 38.471, -29.3893),
	glm::vec3(-32.7254, 23.7764, -29.3893),
	glm::vec3(-38.471, 27.9508, -15.4509),
	glm::vec3(-32.7254, 23.7764, -29.3893),
	glm::vec3(-47.5528, -4.1572e-06, -15.4509),
	glm::vec3(-47.5528, -4.1572e-06, -15.4509),
	glm::vec3(-32.7254, 23.7764, -29.3893),
	glm::vec3(-40.4509, -3.53633e-06, -29.3893),
	glm::vec3(-47.5528, -4.1572e-06, -15.4509),
	glm::vec3(-40.4509, -3.53633e-06, -29.3893),
	glm::vec3(-38.471, -27.9509, -15.4509),
	glm::vec3(-38.471, -27.9509, -15.4509),
	glm::vec3(-40.4509, -3.53633e-06, -29.3893),
	glm::vec3(-32.7254, -23.7764, -29.3893),
	glm::vec3(-38.471, -27.9509, -15.4509),
	glm::vec3(-32.7254, -23.7764, -29.3893),
	glm::vec3(-14.6946, -45.2254, -15.4509),
	glm::vec3(-14.6946, -45.2254, -15.4509),
	glm::vec3(-32.7254, -23.7764, -29.3893),
	glm::vec3(-12.5, -38.471, -29.3893),
	glm::vec3(-14.6946, -45.2254, -15.4509),
	glm::vec3(-12.5, -38.471, -29.3893),
	glm::vec3(14.6946, -45.2254, -15.4509),
	glm::vec3(14.6946, -45.2254, -15.4509),
	glm::vec3(-12.5, -38.471, -29.3893),
	glm::vec3(12.5, -38.471, -29.3893),
	glm::vec3(14.6946, -45.2254, -15.4509),
	glm::vec3(12.5, -38.471, -29.3893),
	glm::vec3(38.4711, -27.9508, -15.4509),
	glm::vec3(38.4711, -27.9508, -15.4509),
	glm::vec3(12.5, -38.471, -29.3893),
	glm::vec3(32.7254, -23.7764, -29.3893),
	glm::vec3(38.4711, -27.9508, -15.4509),
	glm::vec3(32.7254, -23.7764, -29.3893),
	glm::vec3(47.5528, 8.3144e-06, -15.4509),
	glm::vec3(47.5528, 8.3144e-06, -15.4509),
	glm::vec3(32.7254, -23.7764, -29.3893),
	glm::vec3(40.4509, 7.07265e-06, -29.3893),
	glm::vec3(40.4509, 0, -29.3893),
	glm::vec3(29.3893, 0, -40.4509),
	glm::vec3(32.7254, 23.7764, -29.3893),
	glm::vec3(32.7254, 23.7764, -29.3893),
	glm::vec3(29.3893, 0, -40.4509),
	glm::vec3(23.7764, 17.2746, -40.4509),
	glm::vec3(32.7254, 23.7764, -29.3893),
	glm::vec3(23.7764, 17.2746, -40.4509),
	glm::vec3(12.5, 38.471, -29.3893),
	glm::vec3(12.5, 38.471, -29.3893),
	glm::vec3(23.7764, 17.2746, -40.4509),
	glm::vec3(9.08178, 27.9508, -40.4509),
	glm::vec3(12.5, 38.471, -29.3893),
	glm::vec3(9.08178, 27.9508, -40.4509),
	glm::vec3(-12.5, 38.471, -29.3893),
	glm::vec3(-12.5, 38.471, -29.3893),
	glm::vec3(9.08178, 27.9508, -40.4509),
	glm::vec3(-9.08178, 27.9508, -40.4509),
	glm::vec3(-12.5, 38.471, -29.3893),
	glm::vec3(-9.08178, 27.9508, -40.4509),
	glm::vec3(-32.7254, 23.7764, -29.3893),
	glm::vec3(-32.7254, 23.7764, -29.3893),
	glm::vec3(-9.08178, 27.9508, -40.4509),
	glm::vec3(-23.7764, 17.2746, -40.4509),
	glm::vec3(-32.7254, 23.7764, -29.3893),
	glm::vec3(-23.7764, 17.2746, -40.4509),
	glm::vec3(-40.4509, -3.53633e-06, -29.3893),
	glm::vec3(-40.4509, -3.53633e-06, -29.3893),
	glm::vec3(-23.7764, 17.2746, -40.4509),
	glm::vec3(-29.3893, -2.56929e-06, -40.4509),
	glm::vec3(-40.4509, -3.53633e-06, -29.3893),
	glm::vec3(-29.3893, -2.56929e-06, -40.4509),
	glm::vec3(-32.7254, -23.7764, -29.3893),
	glm::vec3(-32.7254, -23.7764, -29.3893),
	glm::vec3(-29.3893, -2.56929e-06, -40.4509),
	glm::vec3(-23.7764, -17.2746, -40.4509),
	glm::vec3(-32.7254, -23.7764, -29.3893),
	glm::vec3(-23.7764, -17.2746, -40.4509),
	glm::vec3(-12.5, -38.471, -29.3893),
	glm::vec3(-12.5, -38.471, -29.3893),
	glm::vec3(-23.7764, -17.2746, -40.4509),
	glm::vec3(-9.08178, -27.9508, -40.4509),
	glm::vec3(-12.5, -38.471, -29.3893),
	glm::vec3(-9.08178, -27.9508, -40.4509),
	glm::vec3(12.5, -38.471, -29.3893),
	glm::vec3(12.5, -38.471, -29.3893),
	glm::vec3(-9.08178, -27.9508, -40.4509),
	glm::vec3(9.08178, -27.9508, -40.4509),
	glm::vec3(12.5, -38.471, -29.3893),
	glm::vec3(9.08178, -27.9508, -40.4509),
	glm::vec3(32.7254, -23.7764, -29.3893),
	glm::vec3(32.7254, -23.7764, -29.3893),
	glm::vec3(9.08178, -27.9508, -40.4509),
	glm::vec3(23.7764, -17.2746, -40.4509),
	glm::vec3(32.7254, -23.7764, -29.3893),
	glm::vec3(23.7764, -17.2746, -40.4509),
	glm::vec3(40.4509, 7.07265e-06, -29.3893),
	glm::vec3(40.4509, 7.07265e-06, -29.3893),
	glm::vec3(23.7764, -17.2746, -40.4509),
	glm::vec3(29.3893, 5.13858e-06, -40.4509),
	glm::vec3(29.3893, 0, -40.4509),
	glm::vec3(15.4508, 0, -47.5528),
	glm::vec3(23.7764, 17.2746, -40.4509),
	glm::vec3(23.7764, 17.2746, -40.4509),
	glm::vec3(15.4508, 0, -47.5528),
	glm::vec3(12.5, 9.08178, -47.5528),
	glm::vec3(23.7764, 17.2746, -40.4509),
	glm::vec3(12.5, 9.08178, -47.5528),
	glm::vec3(9.08178, 27.9508, -40.4509),
	glm::vec3(9.08178, 27.9508, -40.4509),
	glm::vec3(12.5, 9.08178, -47.5528),
	glm::vec3(4.77457, 14.6946, -47.5528),
	glm::vec3(9.08178, 27.9508, -40.4509),
	glm::vec3(4.77457, 14.6946, -47.5528),
	glm::vec3(-9.08178, 27.9508, -40.4509),
	glm::vec3(-9.08178, 27.9508, -40.4509),
	glm::vec3(4.77457, 14.6946, -47.5528),
	glm::vec3(-4.77457, 14.6946, -47.5528),
	glm::vec3(-9.08178, 27.9508, -40.4509),
	glm::vec3(-4.77457, 14.6946, -47.5528),
	glm::vec3(-23.7764, 17.2746, -40.4509),
	glm::vec3(-23.7764, 17.2746, -40.4509),
	glm::vec3(-4.77457, 14.6946, -47.5528),
	glm::vec3(-12.5, 9.08178, -47.5528),
	glm::vec3(-23.7764, 17.2746, -40.4509),
	glm::vec3(-12.5, 9.08178, -47.5528),
	glm::vec3(-29.3893, -2.56929e-06, -40.4509),
	glm::vec3(-29.3893, -2.56929e-06, -40.4509),
	glm::vec3(-12.5, 9.08178, -47.5528),
	glm::vec3(-15.4508, -1.35076e-06, -47.5528),
	glm::vec3(-29.3893, -2.56929e-06, -40.4509),
	glm::vec3(-15.4508, -1.35076e-06, -47.5528),
	glm::vec3(-23.7764, -17.2746, -40.4509),
	glm::vec3(-23.7764, -17.2746, -40.4509),
	glm::vec3(-15.4508, -1.35076e-06, -47.5528),
	glm::vec3(-12.5, -9.08178, -47.5528),
	glm::vec3(-23.7764, -17.2746, -40.4509),
	glm::vec3(-12.5, -9.08178, -47.5528),
	glm::vec3(-9.08178, -27.9508, -40.4509),
	glm::vec3(-9.08178, -27.9508, -40.4509),
	glm::vec3(-12.5, -9.08178, -47.5528),
	glm::vec3(-4.77457, -14.6946, -47.5528),
	glm::vec3(-9.08178, -27.9508, -40.4509),
	glm::vec3(-4.77457, -14.6946, -47.5528),
	glm::vec3(9.08178, -27.9508, -40.4509),
	glm::vec3(9.08178, -27.9508, -40.4509),
	glm::vec3(-4.77457, -14.6946, -47.5528),
	glm::vec3(4.77457, -14.6946, -47.5528),
	glm::vec3(9.08178, -27.9508, -40.4509),
	glm::vec3(4.77457, -14.6946, -47.5528),
	glm::vec3(23.7764, -17.2746, -40.4509),
	glm::vec3(23.7764, -17.2746, -40.4509),
	glm::vec3(4.77457, -14.6946, -47.5528),
	glm::vec3(12.5, -9.08177, -47.5528),
	glm::vec3(23.7764, -17.2746, -40.4509),
	glm::vec3(12.5, -9.08177, -47.5528),
	glm::vec3(29.3893, 5.13858e-06, -40.4509),
	glm::vec3(29.3893, 5.13858e-06, -40.4509),
	glm::vec3(12.5, -9.08177, -47.5528),
	glm::vec3(15.4508, 2.70151e-06, -47.5528),
	glm::vec3(15.4508, 0, -47.5528),
	glm::vec3(-2.18557e-06, -0, -50),
	glm::vec3(12.5, 9.08178, -47.5528),
	glm::vec3(12.5, 9.08178, -47.5528),
	glm::vec3(-1.76816e-06, -1.28465e-06, -50),
	glm::vec3(4.77457, 14.6946, -47.5528),
	glm::vec3(4.77457, 14.6946, -47.5528),
	glm::vec3(-6.75378e-07, -2.0786e-06, -50),
	glm::vec3(-4.77457, 14.6946, -47.5528),
	glm::vec3(-4.77457, 14.6946, -47.5528),
	glm::vec3(6.75378e-07, -2.0786e-06, -50),
	glm::vec3(-12.5, 9.08178, -47.5528),
	glm::vec3(-12.5, 9.08178, -47.5528),
	glm::vec3(1.76816e-06, -1.28465e-06, -50),
	glm::vec3(-15.4508, -1.35076e-06, -47.5528),
	glm::vec3(-15.4508, -1.35076e-06, -47.5528),
	glm::vec3(2.18557e-06, 1.91069e-13, -50),
	glm::vec3(-12.5, -9.08178, -47.5528),
	glm::vec3(-12.5, -9.08178, -47.5528),
	glm::vec3(1.76816e-06, 1.28465e-06, -50),
	glm::vec3(-4.77457, -14.6946, -47.5528),
	glm::vec3(-4.77457, -14.6946, -47.5528),
	glm::vec3(6.75378e-07, 2.0786e-06, -50),
	glm::vec3(4.77457, -14.6946, -47.5528),
	glm::vec3(4.77457, -14.6946, -47.5528),
	glm::vec3(-6.75378e-07, 2.0786e-06, -50),
	glm::vec3(12.5, -9.08177, -47.5528),
	glm::vec3(12.5, -9.08177, -47.5528),
	glm::vec3(-1.76816e-06, 1.28464e-06, -50),
	glm::vec3(15.4508, 2.70151e-06, -47.5528),
};