////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMinSize2.hpp>
#include <yq/tachyon/command/size/AddMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize2DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeYDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize²::init_meta(TachyonMeta::Writer<C>&w)
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
