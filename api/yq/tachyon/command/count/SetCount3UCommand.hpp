////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCount³UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCount³UCommand, CountCommand)
    public:
        SetCount³UCommand(const Header&, const Vector3U&);
    
        const Vector3U&   count() const  { return m_count; }
        
        static void init_meta();
        
        unsigned  x() const { return m_count.x; }
        unsigned  y() const { return m_count.y; }
        unsigned  z() const { return m_count.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCount³UCommand(const Header&);
        SetCount³UCommand(const SetCount³UCommand&, const Header&);
        ~SetCount³UCommand();

    private:
        Vector3U   m_count = ZERO;
        
        SetCount³UCommand(const SetCount³UCommand&) = delete;
        SetCount³UCommand(SetCount³UCommand&&) = delete;
        SetCount³UCommand& operator=(const SetCount³UCommand&) = delete;
        SetCount³UCommand& operator=(SetCount³UCommand&&) = delete;
    };
}
