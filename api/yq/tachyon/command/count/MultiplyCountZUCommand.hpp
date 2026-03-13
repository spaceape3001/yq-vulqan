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
    class MultiplyCountᶻCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountᶻCommand, CountCommand)
    public:
        MultiplyCountᶻCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountᶻCommand(const MultiplyCountᶻCommand&, const Header&);
        MultiplyCountᶻCommand(const Header&);
        ~MultiplyCountᶻCommand();

    private:
        unsigned  m_δz = 0.0;
        
        MultiplyCountᶻCommand(const MultiplyCountᶻCommand&) = delete;
        MultiplyCountᶻCommand(MultiplyCountᶻCommand&&) = delete;
        MultiplyCountᶻCommand& operator=(const MultiplyCountᶻCommand&) = delete;
        MultiplyCountᶻCommand& operator=(MultiplyCountᶻCommand&&) = delete;
    };
}
