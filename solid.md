SRP- The responsibilty in Guard is taking key input for movement

OCP- If someone needs to extend behaviour to Scent trail they wont need to edit the source code, its also flexible for extensions in the future

DIP- VisionCone is a high level module since it deals with  which uses ScentTrail another high level module

```mermaid
classDiagram
      SRP --Guard
      OCP-- ScentTrail
      DIP --VisionCone
      VisionCone
      Guard
      ScentTrail
  

      class VisionCone{
         
}

      class Guard{
         
}

      class ScentTrail{
         
}
      class SRP{
            
       
            
}
      class OCP{
            
       
            
}
      class DIP{
            
       
            
}
      class VisionCone{
          ScentTrail: &m_trail
          Guard: &m_guard
         -enum class:m_state

          void update()
          void setConePos()
          void render()
          void trailCollision()
          void handleCollision()
         

}
      class Guard{
          -bool: m_left
          -bool: m_right
          -double: m_speed
          GuardDirection: m_direction
          sf::RectangleShape: m_guard

          void update()
          void render()

          void movement()


}

      class ScentTrail{
            sf::Vector2f -m_thief
            -void intersects()
            -setPosition()
     -float m_xPos
            -float m_yPos
            -int m_speed
            -int m_health
            -bool m_alive

}
