```mermaid
classDiagram
      StrategyPattern -- VisionCone
      StrategyPattern --Guard
      ObserverPattern --ScentTrail
     
      VisionCone
      Guard
      ScentTrail
  

      class StrategyPattern{
         
}
      class ObserverPattern{
            
       
            
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
