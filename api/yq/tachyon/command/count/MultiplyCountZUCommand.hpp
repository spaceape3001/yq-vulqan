////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class MultiplyCountᶻUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountᶻUCommand, CountCommand)
    public:
        MultiplyCountᶻUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountᶻUCommand(const MultiplyCountᶻUCommand&, const Header&);
        MultiplyCountᶻUCommand(const Header&);
        ~MultiplyCountᶻUCommand();

    private:
        unsigned  m_δz = 0.0;
        
        MultiplyCountᶻUCommand(const MultiplyCountᶻUCommand&) = delete;
        MultiplyCountᶻUCommand(MultiplyCountᶻUCommand&&) = delete;
        MultiplyCountᶻUCommand& operator=(const MultiplyCountᶻUCommand&) = delete;
        MultiplyCountᶻUCommand& operator=(MultiplyCountᶻUCommand&&) = delete;
    };
}
