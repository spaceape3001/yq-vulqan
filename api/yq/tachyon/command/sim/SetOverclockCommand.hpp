////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SimCommand.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {

    /*! \brief SetOverclock NEW tachyons into thread
    
        This is for a batch import of tachyons (presumably from a save file)
        onto a new thread.  (So, no "Push/pull" mechanism here)
    */
    class SetOverclockCommand : public SimCommand {
        YQ_OBJECT_DECLARE(SetOverclockCommand, SimCommand)
    public:
        SetOverclockCommand(const Header&, double);
        
        double    overclock() const { return m_overclock; }
        
        static void init_meta();
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
    
        SetOverclockCommand(const SetOverclockCommand&, const Header&);
        ~SetOverclockCommand();

    private:
        double       m_overclock;

        SetOverclockCommand(const SetOverclockCommand&) = delete;
        SetOverclockCommand(SetOverclockCommand&&) = delete;
        SetOverclockCommand& operator=(const SetOverclockCommand&) = delete;
        SetOverclockCommand& operator=(SetOverclockCommand&&) = delete;
    };
}
