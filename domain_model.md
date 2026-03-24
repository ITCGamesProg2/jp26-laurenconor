```mermaid
classDiagram
      Game..> Window
      Player ..> Window
      Enemy ..> Window
      Game --* HUD
      HUD o-- Map: is made up of
      
      Map --  Window
      Window
      LaurenOshea 
      class Game{
             draw(win:Window)
}

      class Player{
            -float m_xPos
            -float m_yPos
            -int m_speed
            -float m_health
            -bool m_hasKeyCard
            -bool m_alive
            -bool m_hidden
            -int m_points
}
      class Enemy{
            
            -float m_xPos
            -float m_yPos
            -int m_speed
            -int m_health
            -bool m_alive
            
}
      class HUD{
            -int m_time
            -bool m_timeOver

}
      class Map{

}

   class Window


