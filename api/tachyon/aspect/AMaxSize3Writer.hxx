////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMaxSize3.hpp>
#include <tachyon/command/size/AddMaxSize3.hpp>
#include <tachyon/command/size/AddMaxSizeX.hpp>
#include <tachyon/command/size/AddMaxSizeY.hpp>
#include <tachyon/command/size/AddMaxSizeZ.hpp>
#include <tachyon/command/size/MultiplyMaxSize.hpp>
#include <tachyon/command/size/MultiplyMaxSize3.hpp>
#include <tachyon/command/size/MultiplyMaxSizeX.hpp>
#include <tachyon/command/size/MultiplyMaxSizeY.hpp>
#include <tachyon/command/size/MultiplyMaxSizeZ.hpp>
#include <tachyon/command/size/SetMaxSize3.hpp>
#include <tachyon/command/size/SetMaxSizeX.hpp>
#include <tachyon/command/size/SetMaxSizeY.hpp>
#include <tachyon/command/size/SetMaxSizeZ.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize³::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMinSize³>();
        w.property(UNSAFE, "max_size", &AMaxSize³::m_max_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMaxSize³::on_set_max_size3);
        w.slot(UNSAFE, &AMaxSize³::on_set_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³::on_set_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³::on_set_max_sizeZ);

        w.slot(UNSAFE, &AMaxSize³::on_add_max_size3);
        w.slot(UNSAFE, &AMaxSize³::on_add_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³::on_add_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³::on_add_max_sizeZ);
        
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_size3);
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³::on_multiply_max_sizeZ);
    }
}
