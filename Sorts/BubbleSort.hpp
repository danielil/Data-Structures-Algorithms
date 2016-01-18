/**
 * Daniel Sebastian Iliescu
 *
 * An implementation of bubble sort.
 */

#pragma once

#include "Sort.hpp"

namespace Sorts
{
    template < typename T >
    void bubblesort( T* data, const std::size_t size )
    {
        for ( std::size_t idx = 0; idx < size; ++idx )
        {
            for ( std::size_t shiftIdx = 0; shiftIdx < size - 1; ++shiftIdx )
            {
                if ( data[shiftIdx] > data[shiftIdx + 1] )
                {
                    swap( data, shiftIdx, shiftIdx + 1 );
                }
            }
        }
    }
}