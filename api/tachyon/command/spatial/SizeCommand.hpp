////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {
    class SizeCommand : public SpatialCommand {
        YQ_OBJECT_DECLARE(SizeCommand, SpatialCommand)
    public:
        SizeCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        SizeCommand(const SizeCommand&, const Header&);
        virtual ~SizeCommand();
        
    private:

        SizeCommand(const SizeCommand&) = delete;
        SizeCommand(SizeCommand&&) = delete;
        SizeCommand& operator=(const SizeCommand&) = delete;
        SizeCommand& operator=(SizeCommand&&) = delete;
    };
}
