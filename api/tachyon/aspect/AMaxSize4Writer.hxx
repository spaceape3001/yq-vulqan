////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMaxSize4.hpp>
#include <tachyon/command/size/AddMaxSize4Command.hpp>
#include <tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <tachyon/command/size/AddMaxSizeZCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSize4Command.hpp>
#include <tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSizeYCommand.hpp>
#include <tachyon/command/size/MultiplyMaxSizeZCommand.hpp>
#include <tachyon/command/size/SetMaxSize4Command.hpp>
#include <tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <tachyon/command/size/SetMaxSizeYCommand.hpp>
#include <tachyon/command/size/SetMaxSizeZCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize⁴::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMinSize⁴>();
        w.property(UNSAFE, "max_size", &AMaxSize⁴::m_max_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_size4);
        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_sizeW);
        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_sizeX);
        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_sizeY);
        w.slot(UNSAFE, &AMaxSize⁴::on_set_max_sizeZ);

        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_size4);
        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_sizeX);
        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_sizeW);
        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_sizeY);
        w.slot(UNSAFE, &AMaxSize⁴::on_add_max_sizeZ);
        
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_size4);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_sizeW);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_sizeX);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_sizeY);
        w.slot(UNSAFE, &AMaxSize⁴::on_multiply_max_sizeZ);
    }
}
