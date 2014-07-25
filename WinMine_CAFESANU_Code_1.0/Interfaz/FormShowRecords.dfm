object FormShowRecs: TFormShowRecs
  Left = 318
  Top = 98
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'WinMine CAFESANU'
  ClientHeight = 438
  ClientWidth = 755
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 560
    Top = 312
    Width = 121
    Height = 25
    Caption = 'Reiniciar records'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 440
    Top = 312
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 0
    OnClick = Button2Click
  end
  object TabControl1_7: TTabControl
    Left = 8
    Top = 8
    Width = 361
    Height = 209
    TabOrder = 2
    Tabs.Strings = (
      'Nivel 1'
      'Nivel 2'
      'Nivel 3'
      'Nivel 4'
      'Nivel 5'
      'Nivel 6'
      'Nivel 7')
    TabIndex = 0
    OnChange = TabControl1_7Change
    object Label1: TLabel
      Left = 9
      Top = 32
      Width = 9
      Height = 13
      Caption = '1.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 9
      Top = 48
      Width = 9
      Height = 13
      Caption = '2.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 9
      Top = 64
      Width = 9
      Height = 13
      Caption = '3.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 9
      Top = 80
      Width = 9
      Height = 13
      Caption = '4.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 9
      Top = 96
      Width = 9
      Height = 13
      Caption = '5.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 9
      Top = 112
      Width = 9
      Height = 13
      Caption = '6.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 9
      Top = 128
      Width = 9
      Height = 13
      Caption = '7.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 9
      Top = 144
      Width = 9
      Height = 13
      Caption = '8.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 9
      Top = 160
      Width = 9
      Height = 13
      Caption = '9.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 3
      Top = 176
      Width = 15
      Height = 13
      Caption = '10.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 297
      Top = 32
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 297
      Top = 48
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label13: TLabel
      Left = 297
      Top = 64
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 297
      Top = 80
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 297
      Top = 96
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label16: TLabel
      Left = 297
      Top = 112
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label17: TLabel
      Left = 297
      Top = 128
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 297
      Top = 144
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 297
      Top = 160
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label20: TLabel
      Left = 297
      Top = 176
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label21: TLabel
      Left = 25
      Top = 32
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label31: TLabel
      Left = 265
      Top = 32
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label22: TLabel
      Left = 25
      Top = 48
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label24: TLabel
      Left = 25
      Top = 80
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label25: TLabel
      Left = 25
      Top = 96
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label26: TLabel
      Left = 25
      Top = 112
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label27: TLabel
      Left = 25
      Top = 128
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label28: TLabel
      Left = 25
      Top = 144
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label29: TLabel
      Left = 25
      Top = 160
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label30: TLabel
      Left = 25
      Top = 176
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label23: TLabel
      Left = 25
      Top = 64
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label32: TLabel
      Left = 265
      Top = 48
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label33: TLabel
      Left = 265
      Top = 64
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label34: TLabel
      Left = 265
      Top = 80
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label35: TLabel
      Left = 265
      Top = 96
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label36: TLabel
      Left = 265
      Top = 112
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label37: TLabel
      Left = 265
      Top = 128
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label38: TLabel
      Left = 265
      Top = 144
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label39: TLabel
      Left = 265
      Top = 160
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label40: TLabel
      Left = 265
      Top = 176
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
  object TabControl8_14: TTabControl
    Left = 8
    Top = 224
    Width = 361
    Height = 209
    TabOrder = 3
    Tabs.Strings = (
      'Nivel 8'
      'Nivel 9'
      'Nivel 10'
      'Nivel 11'
      'Nivel 12'
      'Nivel 13'
      'Nivel 14')
    TabIndex = 0
    OnChange = TabControl8_14Change
    object Label41: TLabel
      Left = 9
      Top = 32
      Width = 9
      Height = 13
      Caption = '1.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label42: TLabel
      Left = 9
      Top = 48
      Width = 9
      Height = 13
      Caption = '2.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label43: TLabel
      Left = 9
      Top = 64
      Width = 9
      Height = 13
      Caption = '3.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label44: TLabel
      Left = 9
      Top = 80
      Width = 9
      Height = 13
      Caption = '4.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label45: TLabel
      Left = 9
      Top = 96
      Width = 9
      Height = 13
      Caption = '5.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label46: TLabel
      Left = 9
      Top = 112
      Width = 9
      Height = 13
      Caption = '6.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label47: TLabel
      Left = 9
      Top = 128
      Width = 9
      Height = 13
      Caption = '7.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label48: TLabel
      Left = 9
      Top = 144
      Width = 9
      Height = 13
      Caption = '8.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label49: TLabel
      Left = 9
      Top = 160
      Width = 9
      Height = 13
      Caption = '9.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label50: TLabel
      Left = 3
      Top = 176
      Width = 15
      Height = 13
      Caption = '10.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label51: TLabel
      Left = 297
      Top = 32
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label52: TLabel
      Left = 297
      Top = 48
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label53: TLabel
      Left = 297
      Top = 64
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label54: TLabel
      Left = 297
      Top = 80
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label55: TLabel
      Left = 297
      Top = 96
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label56: TLabel
      Left = 297
      Top = 112
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label57: TLabel
      Left = 297
      Top = 128
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label58: TLabel
      Left = 297
      Top = 144
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label59: TLabel
      Left = 297
      Top = 160
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label60: TLabel
      Left = 297
      Top = 176
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label61: TLabel
      Left = 25
      Top = 32
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label71: TLabel
      Left = 265
      Top = 32
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label62: TLabel
      Left = 25
      Top = 48
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label64: TLabel
      Left = 25
      Top = 80
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label65: TLabel
      Left = 25
      Top = 96
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label66: TLabel
      Left = 25
      Top = 112
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label67: TLabel
      Left = 25
      Top = 128
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label68: TLabel
      Left = 25
      Top = 144
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label69: TLabel
      Left = 25
      Top = 160
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label70: TLabel
      Left = 25
      Top = 176
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label63: TLabel
      Left = 25
      Top = 64
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label72: TLabel
      Left = 265
      Top = 48
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label73: TLabel
      Left = 265
      Top = 64
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label74: TLabel
      Left = 265
      Top = 80
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label75: TLabel
      Left = 265
      Top = 96
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label76: TLabel
      Left = 265
      Top = 112
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label77: TLabel
      Left = 265
      Top = 128
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label78: TLabel
      Left = 265
      Top = 144
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label79: TLabel
      Left = 265
      Top = 160
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label80: TLabel
      Left = 265
      Top = 176
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
  object TabControl15_21: TTabControl
    Left = 384
    Top = 8
    Width = 361
    Height = 209
    TabOrder = 4
    Tabs.Strings = (
      'Nivel 15'
      'Nivel 16'
      'Nivel 17'
      'Nivel 18'
      'Nivel 19'
      'Nivel 20'
      'Nivel 21')
    TabIndex = 0
    OnChange = TabControl15_21Change
    object Label81: TLabel
      Left = 9
      Top = 32
      Width = 9
      Height = 13
      Caption = '1.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label82: TLabel
      Left = 9
      Top = 48
      Width = 9
      Height = 13
      Caption = '2.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label83: TLabel
      Left = 9
      Top = 64
      Width = 9
      Height = 13
      Caption = '3.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label84: TLabel
      Left = 9
      Top = 80
      Width = 9
      Height = 13
      Caption = '4.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label85: TLabel
      Left = 9
      Top = 96
      Width = 9
      Height = 13
      Caption = '5.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label86: TLabel
      Left = 9
      Top = 112
      Width = 9
      Height = 13
      Caption = '6.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label87: TLabel
      Left = 9
      Top = 128
      Width = 9
      Height = 13
      Caption = '7.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label88: TLabel
      Left = 9
      Top = 144
      Width = 9
      Height = 13
      Caption = '8.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label89: TLabel
      Left = 9
      Top = 160
      Width = 9
      Height = 13
      Caption = '9.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label90: TLabel
      Left = 3
      Top = 176
      Width = 15
      Height = 13
      Caption = '10.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label91: TLabel
      Left = 297
      Top = 32
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label92: TLabel
      Left = 297
      Top = 48
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label93: TLabel
      Left = 297
      Top = 64
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label94: TLabel
      Left = 297
      Top = 80
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label95: TLabel
      Left = 297
      Top = 96
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label96: TLabel
      Left = 297
      Top = 112
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label97: TLabel
      Left = 297
      Top = 128
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label98: TLabel
      Left = 297
      Top = 144
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label99: TLabel
      Left = 297
      Top = 160
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label100: TLabel
      Left = 297
      Top = 176
      Width = 27
      Height = 13
      Caption = 'Segs.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label101: TLabel
      Left = 25
      Top = 32
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label111: TLabel
      Left = 265
      Top = 32
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label102: TLabel
      Left = 25
      Top = 48
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label104: TLabel
      Left = 25
      Top = 80
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label105: TLabel
      Left = 25
      Top = 96
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label106: TLabel
      Left = 25
      Top = 112
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label107: TLabel
      Left = 25
      Top = 128
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label108: TLabel
      Left = 25
      Top = 144
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label109: TLabel
      Left = 25
      Top = 160
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label110: TLabel
      Left = 25
      Top = 176
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label103: TLabel
      Left = 25
      Top = 64
      Width = 41
      Height = 13
      Caption = 'Anónimo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label112: TLabel
      Left = 265
      Top = 48
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label113: TLabel
      Left = 265
      Top = 64
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label114: TLabel
      Left = 265
      Top = 80
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label115: TLabel
      Left = 265
      Top = 96
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label116: TLabel
      Left = 265
      Top = 112
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label117: TLabel
      Left = 265
      Top = 128
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label118: TLabel
      Left = 265
      Top = 144
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label119: TLabel
      Left = 265
      Top = 160
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label120: TLabel
      Left = 265
      Top = 176
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = '9999'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
end
