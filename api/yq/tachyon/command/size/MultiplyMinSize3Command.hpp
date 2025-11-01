////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMinSize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize³Command, SizeCommand)
    public:
        MultiplyMinSize³Command(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSize³Command(const MultiplyMinSize³Command&, const Header&);
        MultiplyMinSize³Command(const Header&);
        ~MultiplyMinSize³Command();

    private:
        Vector3D  m_δ;
        
        MultiplyMinSize³Command(const MultiplyMinSize³Command&) = delete;
        MultiplyMinSize³Command(MultiplyMinSize³Command&&) = delete;
        MultiplyMinSize³Command& operator=(const MultiplyMinSize³Command&) = delete;
        MultiplyMinSize³Command& operator=(MultiplyMinSize³Command&&) = delete;
    };
}
