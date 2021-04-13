// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Cars/Net/buffer.h"


class CGameBuffer : public Net::CBuffer
{
public:

    CGameBuffer(size_t initSize = 500, size_t delta = 500);
    ~CGameBuffer();

    using CBuffer::write;
    using CBuffer::read;

    void write(const FVector& data);
    void read(FVector& data);
    void write(const FVector2D& data);
    void read(FVector2D& data);
    void write(const FTransform& data);
    void read(FTransform& data);
};
