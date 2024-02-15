///**
//* 백준 ﻿영수증 25304
//* input들의 합이 올바른지 확인하는 로직
//* 
//* X = checkValue
//* N = numberOfMerchandise
//* a = priceOfMerchandise
//* b = sizeOfMerchandise
//* 
//* 제한사항
//*****************************************
//* 1 ≤ X ≤ 1,000,000,000				* 
//* 1 ≤ N ≤ 100							*
//* 1 ≤ a ≤ 1,000,000					*
//* 1 ≤ b ≤ 10							*
//*****************************************
//*
//*
//*
//* 주의
//* 
//* 풀이시간 1분
//*/
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//int main(void)
//{
//	int X, N, a, b;
//	scanf("%d", &X);
//	scanf("%d", &N);
//	for (int i = 0; i < N; ++i)
//	{
//		scanf("%d%d", &a, &b);
//		X -= a * b;
//
//	}
//
//	if (X == 0)
//	{
//		printf("Yes");
//	}
//	else
//	{
//		printf("No");
//	}
//
//	return 0;
//}