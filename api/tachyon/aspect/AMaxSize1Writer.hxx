////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMaxSize1.hpp>
#include <tachyon/command/size/AddMaxSize1.hpp>
#include <tachyon/command/size/AddMaxSizeX.hpp>
#include <tachyon/command/size/MultiplyMaxSize.hpp>
#include <tachyon/command/size/MultiplyMaxSize1.hpp>
#include <tachyon/command/size/MultiplyMaxSizeX.hpp>
#include <tachyon/command/size/SetMaxSize1.hpp>
#include <tachyon/command/size/SetMaxSizeX.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize¹::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<IMaxSize¹>();
        w.property(UNSAFE, "max_size", &AMaxSize¹::m_max_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &AMaxSize¹::on_set_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_set_max_sizeX);

        w.slot(UNSAFE, &AMaxSize¹::on_add_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_add_max_sizeX);
        
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_size1);
        w.slot(UNSAFE, &AMaxSize¹::on_multiply_max_sizeX);
    }
}
