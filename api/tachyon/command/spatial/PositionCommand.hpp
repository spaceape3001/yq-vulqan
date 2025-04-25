////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {
    class PositionCommand : public SpatialCommand {
        YQ_OBJECT_DECLARE(PositionCommand, SpatialCommand)
    public:
        PositionCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        PositionCommand(const PositionCommand&, const Header&);
        virtual ~PositionCommand();
        
    private:

        PositionCommand(const PositionCommand&) = delete;
        PositionCommand(PositionCommand&&) = delete;
        PositionCommand& operator=(const PositionCommand&) = delete;
        PositionCommand& operator=(PositionCommand&&) = delete;
    };
}
