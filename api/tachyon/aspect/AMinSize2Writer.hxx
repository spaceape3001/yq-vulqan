////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AMinSize2.hpp>
#include <tachyon/command/size/AddMinSize2Command.hpp>
#include <tachyon/command/size/AddMinSizeXCommand.hpp>
#include <tachyon/command/size/AddMinSizeYCommand.hpp>
#include <tachyon/command/size/MultiplyMinSizeCommand.hpp>
#include <tachyon/command/size/MultiplyMinSize2Command.hpp>
#include <tachyon/command/size/MultiplyMinSizeXCommand.hpp>
#include <tachyon/command/size/MultiplyMinSizeYCommand.hpp>
#include <tachyon/command/size/SetMinSize2Command.hpp>
#include <tachyon/command/size/SetMinSizeXCommand.hpp>
#include <tachyon/command/size/SetMinSizeYCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize²::init_info(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMinSize²>();
        w.property(UNSAFE, "min_size", &AMinSize²::m_min_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMinSize²::on_set_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_set_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_set_min_sizeY);

        w.slot(UNSAFE, &AMinSize²::on_add_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_add_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_add_min_sizeY);
        
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_size2);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_sizeX);
        w.slot(UNSAFE, &AMinSize²::on_multiply_min_sizeY);
    }
}
