// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBuffer.h"


CGameBuffer::CGameBuffer(size_t initSize, size_t delta)
    : CBuffer(initSize, delta)
{}

CGameBuffer::~CGameBuffer() {}

void CGameBuffer::write(const FVector& data)
{
    write(data.X);
    write(data.Y);
    write(data.Z);
}

void CGameBuffer::read(FVector& data)
{
    read(data.X);
    read(data.Y);
    read(data.Z);
}

void CGameBuffer::write(const FVector2D& data)
{
    write(data.X);
    write(data.Y);
}

void CGameBuffer::read(FVector2D& data)
{
    read(data.X);
    read(data.Y);
}
