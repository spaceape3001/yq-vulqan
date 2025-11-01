////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMaxSize4.hpp>
#include <yq/tachyon/command/size/AddMaxSize4Command.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize4Command.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeZCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize4Command.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

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
