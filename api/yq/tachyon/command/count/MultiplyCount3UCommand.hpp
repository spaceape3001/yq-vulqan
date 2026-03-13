////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyCount³UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCount³UCommand, CountCommand)
    public:
        MultiplyCount³UCommand(const Header&, const Vector3U&);
    
        const Vector3U&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        unsigned  δx() const { return m_δ.x; }
        unsigned  δy() const { return m_δ.y; }
        unsigned  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCount³UCommand(const MultiplyCount³UCommand&, const Header&);
        MultiplyCount³UCommand(const Header&);
        ~MultiplyCount³UCommand();

    private:
        Vector3U  m_δ;
        
        MultiplyCount³UCommand(const MultiplyCount³UCommand&) = delete;
        MultiplyCount³UCommand(MultiplyCount³UCommand&&) = delete;
        MultiplyCount³UCommand& operator=(const MultiplyCount³UCommand&) = delete;
        MultiplyCount³UCommand& operator=(MultiplyCount³UCommand&&) = delete;
    };
}
