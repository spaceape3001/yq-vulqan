////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Command.hpp>

namespace yq::tachyon {
    class Camera;

    class CameraCommand : public Command {
        YQ_OBJECT_DECLARE(CameraCommand, Command)
    public:

        static void init_meta();

    protected:
        CameraCommand(const Header&);
        CameraCommand(const CameraCommand&, const Header& h);
        virtual ~CameraCommand();
        
    private:
        CameraCommand(const CameraCommand&) = delete;
        CameraCommand(CameraCommand&&) = delete;
        CameraCommand& operator=(const CameraCommand&) = delete;
        CameraCommand& operator=(CameraCommand&&) = delete;
    };
}
