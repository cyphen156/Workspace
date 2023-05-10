package week10;

public class TV {
    private Boolean powerOn = false;
    private Boolean muteOn = false;

    public void power(){
        powerOn =! powerOn;

        if (powerOn == true) {
            System.out.println("power On");
        }else
            System.out.println("power Off");
    }

    public void mute() {
        if (!powerOn)
            return;

        muteOn =! muteOn;

        if (muteOn == true) {
            System.out.println("mute On");
        }else
            System.out.println("mute On");
    }
}
