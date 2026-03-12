////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMinSize1.hpp>
#include <yq/tachyon/command/size/AddMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/AddMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMinSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMinSize1DCommand.hpp>
#include <yq/tachyon/command/size/SetMinSizeXDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMinSize¹::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMinSize¹>();
        w.property(UNSAFE, "min_size", &AMinSize¹::m_min_size).tag(kTag_Save);
        
        w.slot(UNSAFE, &AMinSize¹::on_set_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_set_min_sizeX);

        w.slot(UNSAFE, &AMinSize¹::on_add_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_add_min_sizeX);
        
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_size);
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_size1);
        w.slot(UNSAFE, &AMinSize¹::on_multiply_min_sizeX);
    }
}
