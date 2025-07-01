////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {
    class OrientationCommand : public SpatialCommand {
        YQ_OBJECT_DECLARE(OrientationCommand, SpatialCommand)
    public:
        OrientationCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        OrientationCommand(const OrientationCommand&, const Header&);
        virtual ~OrientationCommand();
        
    private:

        OrientationCommand(const OrientationCommand&) = delete;
        OrientationCommand(OrientationCommand&&) = delete;
        OrientationCommand& operator=(const OrientationCommand&) = delete;
        OrientationCommand& operator=(OrientationCommand&&) = delete;
    };
}
