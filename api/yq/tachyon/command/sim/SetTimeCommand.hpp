////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SimCommand.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {

    /*! \brief SetTime NEW tachyons into thread
    
        This is for a batch import of tachyons (presumably from a save file)
        onto a new thread.  (So, no "Push/pull" mechanism here)
    */
    class SetTimeCommand : public SimCommand {
        YQ_OBJECT_DECLARE(SetTimeCommand, SimCommand)
    public:
        SetTimeCommand(const Header&, unit::Second);
        
        unit::Second    time() const { return m_time; }
        
        static void init_meta();
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
    
        SetTimeCommand(const SetTimeCommand&, const Header&);
        ~SetTimeCommand();

    private:
        unit::Second        m_time;

        SetTimeCommand(const SetTimeCommand&) = delete;
        SetTimeCommand(SetTimeCommand&&) = delete;
        SetTimeCommand& operator=(const SetTimeCommand&) = delete;
        SetTimeCommand& operator=(SetTimeCommand&&) = delete;
    };
}
