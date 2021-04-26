using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Trigger : MonoBehaviour
{
    int lv;
    bool Finish = false;
    bool fin = false;
    public GameObject wintext;
    public GameObject losetext;
    public Text lvtext;

    private void Start()
    {
        lv = SC.getLv();
        lvtext.text = "Lv " + lv;
    }
    public bool finish()
    {
        return Finish;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Enemy" && !fin)
        {
            Invoke("w", 1f);
            fin = true;
        }

        if (other.gameObject.tag == "Spin" && !fin)
        {
            Invoke("l", 1f);
            fin = true;
        }
    }

    public void ClickWin()
    {
        wintext.SetActive(false);
        Finish = false;
    }

    public void ClickLose()
    {
        losetext.SetActive(false);
        Finish = false;
    }

    public void w()
    {
        int a = PlayerPrefs.GetInt("BATTLE", 0);
        a++;
        PlayerPrefs.SetInt("BATTLE", a);
        PlayerPrefs.Save();
        int b = PlayerPrefs.GetInt("LV", 0);
        if (b < lv) b = lv;
        PlayerPrefs.SetInt("LV", b);
        PlayerPrefs.Save();
        Debug.Log("LV:" + b);
        wintext.SetActive(true);
        Finish = true;
    }
    public void l()
    {
        int a = PlayerPrefs.GetInt("BATTLE", 0);
        a++;
        PlayerPrefs.SetInt("BATTLE", a);
        PlayerPrefs.Save();
        losetext.SetActive(true);
        Finish = true;
    }
}
