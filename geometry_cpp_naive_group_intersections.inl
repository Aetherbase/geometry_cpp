


#include "geometry_cpp.hpp"
#include "geometry_cpp_algorithm.hpp"

#include <vector>
#include <algorithm>


namespace geometry_cpp
{
   namespace algorithm
   {
      template <typename T>
      struct naive_group_intersections< segment<T,2> >
      {
      public:

         template <typename InputIterator, typename OutputIterator>
         naive_group_intersections(InputIterator begin, InputIterator end, OutputIterator out)
         {
            for (InputIterator i = begin; i != end; ++i)
            {
               for (InputIterator j = (i + 1); j != end; ++j)
               {
                  if (intersect((*j),(*i)))
                  {
                     (*out++) = intersection_point((*j),(*i));
                  }
               }
            }
         }
      };

      template <typename T>
      struct naive_group_intersections< segment<T,3> >
      {
      public:

         template <typename InputIterator, typename OutputIterator>
         naive_group_intersections(InputIterator begin, InputIterator end, OutputIterator out)
         {
            for (InputIterator i = begin; i != end; ++i)
            {
               for (InputIterator j = (i + 1); j != end; ++j)
               {
                  if (intersect((*j),(*i)))
                  {
                     (*out++) = intersection_point((*j),(*i));
                  }
               }
            }
         }
      };

      template <typename T>
      struct naive_group_intersections< circle<T> >
      {
      public:

         template <typename InputIterator, typename OutputIterator>
         naive_group_intersections(InputIterator begin, InputIterator end, OutputIterator out)
         {
            for (InputIterator i = begin; i != end; ++i)
            {
               for (InputIterator j = (i + 1); j != end; ++j)
               {

                  if (
                       (distance((*i).x,(*i).y,(*j).x,(*j).y) >= std::abs((*i).radius - (*j).radius)) &&
                       intersect((*j),(*i))
                     )
                  {
                     point2d<T> p1;
                     point2d<T> p2;

                     intersection_point((*j),(*i),p1,p2);

                     (*out++) = p1;
                     (*out++) = p2;
                  }
               }
            }
         }
      };

   } // namespace geometry_cpp::algorithm

} // namespace geometry_cpp
